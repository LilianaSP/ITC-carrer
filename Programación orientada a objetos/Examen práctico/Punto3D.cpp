#include "Punto3D.h"
#include <iostream>
#include <string>
#include <sstream>

Punto3D::Punto3D(){
    z = 0;
}

//realizamos la herencia de los atributos
Punto3D::Punto3D(int _x, int _y, int _z):Punto2D(_x, _y){
    z = _z;
}

//definimos el getter del atributo propio de punto3D
int Punto3D::getZ() const{
    return z;
}

    void Punto3D::setZ(int _z){
    z = _z;
}

std::string Punto3D::mostrar(){
    std::ostringstream oss;
    oss << Punto2D::mostrar() << " Coordenada en z: "  << z << std::endl;
    std::string imprimeCoord = oss.str();
    return imprimeCoord; //imprimiemos los datos
}