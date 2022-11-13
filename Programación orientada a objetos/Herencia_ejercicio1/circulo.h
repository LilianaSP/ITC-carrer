
#ifndef CIRCULO_H
#define CIRCULO_H
#include<iostream>
#include "Figura.h"
using namespace std;
const static double PI = 3.14159; //Funciona en toda la clase

class Circulo: public Figura{ //Herencia de clases de circulo a figura
    public:
        Circulo();
        Circulo(int, int, int); //inicializamos las variables de la clase figura
        int getRadio() const;
        void setRadio(int);
        string dibuja();
        double area() ;
        

    private:
        int radio;
        

};


#endif