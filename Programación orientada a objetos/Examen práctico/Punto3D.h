#ifndef PUNTO3D_h
#define PUNTO3D_h
#include "Punto2D.h" 
#include <iostream>

//Creamos la clase punto y hacemos la herencia de los atributos
class Punto3D:public Punto2D{
    //Creamos los atribubtos
    private:
        int z; //Se agrega z únicamente porque es en 3D y este hereda las coords en x y y de la clase punto2D

    public:
        Punto3D();
        Punto3D(int, int, int); //Los parámetros que recibe, se incluye el de la calse que hereda
        int getZ() const; //coord en z para hacerlo 3D
        void setZ(int);
        std::string mostrar() override; //se determina override ya que esta es una funcion virtual
};

#endif