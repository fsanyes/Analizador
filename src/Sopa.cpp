#include <Sopa.hpp>

//constructor
Sopa::Sopa(string ruta)
{
    ifstream archivo(ruta);
    string linea;
    char mayus;
    if (archivo.good())
    {
        vector<char> fila;
        while (getline(archivo, linea))
        {
            //cout << linea << endl;
            for (int i=0; i<linea.size(); i++)
            {
                
                if (linea[i]>=' ' && linea[i]<='@')
                {
                    linea.erase(i,1);
                }
                //cambia la ñ por n
                /*else if (linea[i]==(char)164)
                {
                    linea[i]='n';
                }*/
                fila.push_back(linea[i]); 
            }
            for (int j=0; j<fila.size(); j++)
            {
                if (fila[j]>='A' && fila[j]<='Z')
                {
                    //Combierte a minuscula
                    fila[j]=tolower(fila[j]);

                }
            }
            sopaLetras.push_back(fila);
            fila.clear();
        }
        maxCol=sopaLetras[0].size();
        maxFil=sopaLetras.size();
        direcFil=0;
        direcCol=1;
        fil=0;
        col=0;
        seguir=true;
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

//Getters

int Sopa::getMaxFil()
{
    return maxFil;
}
int Sopa::getMaxCol()
{
    return maxCol;
}
int Sopa::getDirecFil()
{
    return direcFil;
}
int Sopa::getDirecCol()
{
    return direcCol;
}
int Sopa::getFil()
{
    return fil;
}
int Sopa::getCol()
{
    return col;
}
bool Sopa::getSeguir()
{
    return seguir;
}

//Setters

void Sopa::setMaxFil(int maxFil)
{
    this->maxFil=maxFil;
}
void Sopa::setMaxCol(int maxCol)
{
    this->maxCol=maxCol;
}
void Sopa::setDirecFil(int direcFil)
{
    this->direcFil=direcFil;
}
void Sopa::setDirecCol(int direcCol)
{
    this->direcCol=direcCol;
}
void Sopa::setFil(int fil)
{
    this->fil=fil;
}
void Sopa::setCol(int col)
{
    this->col=col;
}
void Sopa::setSeguir(bool seguir)
{
    this->seguir=seguir;
}

//Funciones
void Sopa::cambiaDireccion(int opcion)
{
    
    switch (opcion)
    {
    case 0: //Derecha---->
        
        setDirecFil(0);
        setDirecCol(1);
        break;
    case 1: //Diagonal Abajo Derecha-->
        setDirecFil(1);
        setDirecCol(1);
        break;
    case 2: //Abajo
        setDirecFil(1);
        setDirecCol(0);
        break;
    case 3: //Diagonal Abajo Izquierda <--
        setDirecFil(1);
        setDirecCol(-1);
        break;
    case 4: //Izquierda <--
        setDirecFil(0);
        setDirecCol(-1);
        break;
    case 5: //Diagonal Izquierda Arriba <--
        setDirecFil(-1);
        setDirecCol(-1);
        break;
    case 6: //Arriba
        setDirecFil(-1);
        setDirecCol(0);
        break;
    case 7: //Diagonal Derecha Arriba -->
        setDirecFil(-1);
        setDirecCol(1);
        break;
    }
    
}
//Encoje la capacidad del vector para ahorrar memoria
void Sopa::liberaMemoria()
{
    this->sopaLetras.shrink_to_fit();
}

bool Sopa::esta_fuera(int &fil, int &col, int &maxFil, int &maxCol)
{
    if (fil < 0 || col < 0 )
    {
        return true;
    }
    else if (fil >= maxFil || col >= maxCol)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//busca palabras en la sopa de letras
void Sopa::buscarPalabra(vector<string>palabras)
{
    string palabra;
    int vecesEncontrada=0;
    for (int p=0; p<palabras.size(); p++)
    {
        //Almacenamos la palabra que vamos a buscar
        palabra=palabras[p];
        //cout << "Buscando la palabra:" << palabra << endl;

        for (int i=0; i<sopaLetras.size(); i++)
        {
            for (int j=0; j<sopaLetras[i].size(); j++)
            {
                //Busca la primera letra de la palabra en la sopa de letras
                if (sopaLetras[i][j]==palabra[0])
                {
                
                    for (int opcion=0; opcion<8; opcion++)
                    {
                        cambiaDireccion(opcion);
                        seguir=true;
                        fil=i;
                        col=j;
                        for (int l=1; l<palabra.size(); l++)
                        {
                            fil=fil+direcFil;
                            col=col+direcCol;
                            if (esta_fuera(fil,col, maxFil, maxCol))
                            {
                                seguir=false;
                                break;
                            }
                            else if (palabra[l]!=sopaLetras[fil][col])
                            {
                                seguir=false;
                                break;
                            }
                        }
                        if (seguir==true)
                        {
                            this->palabrasEncontradas.push_back(palabra);
                            vecesEncontrada++;
                            //cout << "Nº de veces encontrada: "<< vecesEncontrada << endl;
                            break;
                        }
                        vecesEncontrada=0;
                    }
                }
            }
        }
    }
}

void Sopa::imprimirSopa()
{
    for (int i=0; i<maxFil; i++)
    {
        for (int j=0; j<maxCol; j++)
        {
            cout << sopaLetras[i][j] << " ";
        }
        cout << endl;
    }
}
void Sopa::imprimirPalabrasEncontradas()
{
    cout << "Las palabras: ";
    for (int i=0; i<palabrasEncontradas.size(); i++)
    {
        cout << palabrasEncontradas[i] << ", ";
    }
    cout << "se encuentran en la sopa" << endl << endl;
}