#include "Rectangulo.h"


Rectangulo::Rectangulo(){
    largo = 1;
    ancho = 1;
}

Rectangulo::Rectangulo(int x, int y, int largo, int ancho):Figura(x,y){
    this-> largo = largo;
    this-> ancho = ancho;
}

int Rectangulo::getAncho() const{
    return this -> ancho;
}

int Rectangulo::getLargo() const{
    return this -> largo;
}

void Rectangulo::setAncho(int ancho){
    this-> ancho = ancho;
}

void Rectangulo::setLargo(int largo){
    this-> largo = largo;
}

std::string Rectangulo::dibuja(){
    return Figura::dibuja() + ": Rectangulo";
}

double Rectangulo::area(){
    return this->largo * this->ancho;
}