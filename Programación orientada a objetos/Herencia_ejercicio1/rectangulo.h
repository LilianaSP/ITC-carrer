#ifndef RECTANGULO_H
#define RECTANGULO_H
#include<iostream>
#include "Figura.h"
using namespace std;

class Rectangulo:public Figura{

    private:
        int largo;
        int ancho;

    public:
        Rectangulo();
        Rectangulo(int, int, int, int); //inicializamos las variables de la clase figura

        int getAncho() const;
        int getLargo() const;

        void setAncho(int);
        void setLargo(int);

        string dibuja();

        double area_r();

};




#endif