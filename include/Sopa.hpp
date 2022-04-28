#ifndef SOPA_HPP
#define SOPA_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Sopa
{
    private:
        vector <vector<char>> sopaLetras;
        vector <string> palabrasEncontradas;
        int maxFil;
        int maxCol;
        int fil;
        int col;
        int direcFil;
        int direcCol;
        bool seguir;

    public:
        //Constructor
        Sopa(string ruta);
        
        //Getters
        int getMaxFil();
        int getMaxCol();
        int getDirecFil();
        int getDirecCol();
        int getFil();
        int getCol();
        bool getSeguir();

        //Setters
        void setMaxFil(int maxFil);
        void setMaxCol(int maxCol);
        void setDirecFil(int direcFil);
        void setDirecCol(int direcCol);
        void setFil(int fil);
        void setCol(int col);
        void setSeguir(bool seguir);

        //Funciones
        void buscarPalabra(vector<string>palabras);
        void cambiaDireccion(int opcion);
        void liberaMemoria();
        bool esta_fuera(int &fil, int &col, int &maxFil, int &maxCol);
        void imprimirSopa();
        void imprimirPalabrasEncontradas();
};

#endif