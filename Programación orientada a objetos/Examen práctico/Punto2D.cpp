#include "Punto2D.h"
#include<iostream>
#include <string>
#include <sstream>

Punto2D::Punto2D(){
    //inicializamos sus atributos en 0
    x = 0;
    y = 0;
}

Punto2D::Punto2D(int _x, int _y){
    x = _x;
    y = _y;
}

//getters
int Punto2D::getX() const{
    return x;
}

int Punto2D::getY() const{
    return y;
}

//métodos setters
void Punto2D::setX(int _x){
    x = _x;
}

void Punto2D::setY(int _y){
    y = _y;
}

std::string Punto2D::mostrar(){
    std::ostringstream oss;
    oss<< "+Coordenadas del Punto+"<< std::endl<< "Coordenadas en x: "<< x << std::endl<< "Coordenadas en y: " << y << std::endl;
    std::string imprimeCoord = oss.str();
    return imprimeCoord;
}

std::ostream &operator << (std::ostream & salida, Punto2D*& _Punto2D){
    salida << _Punto2D->mostrar() << std::endl;
    return salida;
}