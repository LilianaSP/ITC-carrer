#include "Punto.h"
#include <string>
#include <sstream>

Punto::Punto(){
    x = 0;
    y = 0;
}

Punto::Punto(int _x, int _y){
    x = _x;
    y = _y;
}

int Punto::getX() const{
    return x;
}

int Punto::getY() const{
    return y;
}

void Punto::setX(int _x){
    x = _x;
}

void Punto::setY(int _y){
    y = _y;
}

std::string Punto::mostrar(){
    std::ostringstream oss;
    oss << "Coordenadas = x: " << this->x << ", y: " << this->y;
    std::string mostrarVar = oss.str();
    return mostrarVar;
}

std::ostream &operator << (std::ostream & salida, Punto*& _Punto){
    salida << _Punto->mostrar() << std::endl;
    return salida;
}