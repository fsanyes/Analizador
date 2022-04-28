#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Analizador 
{
    private:
        map<string,int> mapaPalabras;
        vector<string> palabras_encontradas;
        int contCaracteres;
        int contConEspacios;
        int maxCantidad;
        int minCantidad;
        

    public:
        //Constructor
        Analizador(string ruta);

        //Getters
        map<string,int> getMapaPalabras();
        const vector<string> getPalabrasEncontradas();
        int getContCaracteres();
        int getContConEspacios();
        int getTotalPalabras();

        //Setters

        //Funciones
        int mediaCaracteres();
        string masRepetida();
        string menosRepetida();
        void mediaContenido();
        void imprimirAnalizador();
        void imprimirPalabrasVertical();
};

#endif