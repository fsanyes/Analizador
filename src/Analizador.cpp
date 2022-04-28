#include <Analizador.hpp>


// Constructor
Analizador::Analizador(string ruta)
{
    ifstream archivo(ruta);
    string linea;
    string contenido;
    if (archivo.good())
    {
        //Lee el archivo y guarda todo su contenido en un string
        while (getline(archivo, linea))
        {
           
            contenido+=(linea+" ");
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }

    //Almacena las palabras en un vector
    //Para despues utilizarlo en la sopa de letras
    
    string palabra;
    contCaracteres=0;
    contConEspacios=0;
    for (int i=0; i<contenido.size(); i++)
    {   
        contConEspacios++;
        if (contenido[i]>='!' && contenido[i]<='@')
        {
            i++;
        }
        if (contenido[i]==' ')
        {
            palabras_encontradas.push_back(palabra);
            palabra.clear();
            
        }
        if (contenido[i]>='A' && contenido[i]<='Z')
        {
            //Combierte a minuscula
            //contenido[i]=tolower(contenido[i]);
            palabra+=tolower(contenido[i]);

        }
        else if (contenido[i]>='a' && contenido[i]<='z')
        {
            palabra+=contenido[i];
            contCaracteres++;
        }
    }
    
    //Almacena el vector en un mapa sumando las palabras repetidas
    maxCantidad=-1;
    minCantidad=1;
    for (int i=0; i<palabras_encontradas.size(); i++)
    {
        if (mapaPalabras.count(palabras_encontradas[i])==0)
        {
            mapaPalabras[palabras_encontradas[i]]=1;
        }
        else
        {
            mapaPalabras[palabras_encontradas[i]]++;//Suma it->second
            if (mapaPalabras[palabras_encontradas[i]]>maxCantidad)
            {
                maxCantidad=mapaPalabras[palabras_encontradas[i]];
            }
        }
    }
}

//Getters
map<string, int> Analizador::getMapaPalabras()
{
    return mapaPalabras;
}
const vector<string> Analizador::getPalabrasEncontradas()
{
    return palabras_encontradas;
}
int Analizador::getContCaracteres()
{
    return contCaracteres;
}
int Analizador::getContConEspacios()
{
    return contConEspacios;
}
int Analizador::getTotalPalabras()
{
    return palabras_encontradas.size();
}
//Setters

//Funciones
int Analizador::mediaCaracteres()
{
    
    int totalPalabras=getTotalPalabras();
    int caracteres=getContCaracteres();
    int media=0;
    media=caracteres/totalPalabras;
    return media;
}
string Analizador::masRepetida()
{
    
    string palabra;
    map<string,int>::iterator it;
    for (it=mapaPalabras.begin(); it!=mapaPalabras.end(); ++it)
    {
        if (it->second==maxCantidad)
        {
            palabra=it->first;
        }
    }
    return palabra;
}
string Analizador::menosRepetida()
{
    
    string palabra;
    map<string,int>::iterator it;
    for (it=mapaPalabras.begin(); it!=mapaPalabras.end(); ++it)
    {
        if (it->second==minCantidad)
        {
            palabra=it->first;
            break;
        }
    }
    return palabra;
}
void Analizador::imprimirAnalizador()
{
    //Imprime el contenido del mapa
    map <string,int>::iterator it;
    int simbolos=0;
    for (it=mapaPalabras.begin(); it!=mapaPalabras.end(); it++)
    {
        cout << it->first << ": " ;
        while (simbolos<it->second)
        {
            cout << "$";
            simbolos++;
        }
        cout << "(" << it->second<< ")" << endl;
        simbolos=0;
    }
}
void Analizador::imprimirPalabrasVertical()
{
    //Imprime las palabras en forma vertical
    int contador=10;
    int simbolos=0;
    map<string,int>::iterator it, it2;
    map<string,int> copia;
    int masRepet=maxCantidad;
    int palabraMasLarga=0;
    while (contador!=0)
    {
        for (it=mapaPalabras.begin(); it!=mapaPalabras.end(); it++)
        {
            if (it->second==masRepet)
            {
                
                
                //cout << it->first << " ";
                if (it->first.size()>palabraMasLarga)
                {
                    palabraMasLarga=it->first.size();
                }
                copia[it->first]=it->second;
                contador--;
                simbolos=0;
            }
            if (contador==0)
            {
                break;
            }
        }
        cout << endl;
        masRepet--;
    }
    string palabra;
    int maxSimbolos=maxCantidad;
    //Imprime los simbolos de forma vertical
    for (int j=0; j<maxCantidad; j++)
    {
        for (it2=copia.begin(); it2!=copia.end(); it2++)
        {
            if (it2->second==maxSimbolos)
            {
                cout << "$ ";
                it2->second--;
            }
            if (it->second==0)
            {
                it->second==100000000;
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
        maxSimbolos--;
    }
    //Imprime las palabras de forma vertical
    int pos=0;
    for (int i=0; i<palabraMasLarga; i++)
    {
        for(it=copia.begin(); it!=copia.end(); it++)//Utilizar palabraMasLarga Para imprimir el bucle
        {
            palabra=it->first;
            if (pos<palabra.size())
            {
                cout << palabra[pos] << "   ";
            }
            else if (pos>palabra.size())
            {
                cout << "    ";
                
            }
        }
        pos++;
        cout << endl;
        //cout << it->first << " " << endl;
        simbolos=0;
    }
    
}
