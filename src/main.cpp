#include <iostream>
#include <Analizador.hpp>
#include <Sopa.hpp>

using namespace std;

int main()
{
    /*------------------------Analizador de palabras/Sopa de letras----------------------------*/
    string ruta;
    cout << "-----------------------Analizador de palabras/Sopa de letras-----------------------" << endl;
    cout << "Selecciona modo del programa:" << endl;
    cout << "1. Analizador de palabras" << endl;
    cout << "2. Sopa de letras" << endl;
    cout << "3. Ambos" << endl;
    cout << "4. Salir" << endl;
    int menu=0;
    
    while (menu>4 || menu<1)
    {
        cout << "Ingrese una opcion valida" << endl;
        cin >> menu;
    }
    
    if (menu==1)
    {
        //Analizador de palabras
        cout << endl << "Ingrese la ruta del archivo: ";
        cin >> ruta;
        cout << endl;
        Analizador analizador(ruta);
        analizador.imprimirAnalizador();
        analizador.imprimirPalabrasVertical();
        cout << endl;
        cout << "Total de caracteres:" << analizador.getContCaracteres() << endl;
        cout << "Total de caracteres con espacios y simbolos:" << analizador.getContConEspacios() << endl;
        cout << "Media de longitud de palabras:" << analizador.mediaCaracteres() << endl;
        cout << "Palabra mas repetida:" << analizador.masRepetida() << endl;
        cout << "Palabra menos repetida:" << analizador.menosRepetida() << endl;
        cout << "Gracias por usar el programa" << endl;
    }
    else if (menu==2)
    {
        //Sopa de letras
        cout << endl << "Ingrese la ruta del archivo: ";
        cin >> ruta;
        cout << endl;
        Sopa sopa(ruta);
        sopa.imprimirSopa();
        cout << "ingrese la palabra a buscar: ";
        string palabra;
        cin >> palabra;
        vector<string> busqueda;
        busqueda.push_back(palabra);
        sopa.buscarPalabra(busqueda);
        sopa.imprimirPalabrasEncontradas();
        cout << "Gracias por usar el programa" << endl;
    }
    else if (menu==3)
    {
        //Analizador
        cout << endl << "Ingrese la ruta del archivo (Analizador): ";
        cin >> ruta;
        cout << endl;
        Analizador analizador(ruta);
        analizador.imprimirAnalizador();
        analizador.imprimirPalabrasVertical();
        cout << endl;
        cout << "Total de caracteres:" << analizador.getContCaracteres() << endl;
        cout << "Total de caracteres con espacios y simbolos:" << analizador.getContConEspacios() << endl;
        cout << "Media de longitud de palabras:" << analizador.mediaCaracteres() << endl;
        cout << "Palabra mas repetida:" << analizador.masRepetida() << endl;
        cout << "Palabra menos repetida:" << analizador.menosRepetida() << endl;
        //Sopa de letras
        cout << endl << "Ingrese la ruta del archivo (Sopa De Letras): ";
        cin >> ruta;
        cout << endl;
        Sopa sopa(ruta);
        sopa.buscarPalabra(analizador.getPalabrasEncontradas());
        sopa.imprimirSopa();
        sopa.imprimirPalabrasEncontradas();
        cout << "Gracias por usar el programa" << endl;
    }
    else if (menu==4)
    {
        cout << "Gracias por usar el programa" << endl;
    }

    return 0;
}
