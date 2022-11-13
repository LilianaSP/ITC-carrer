#include "Pixel.h"
#include <string>
#include <sstream>

Pixel::Pixel(){
    color = "";
}

Pixel::Pixel(int _x, int _y, std::string _color):Punto(_x, _y){
    color = _color;
}

std::string Pixel::getColor() const{
    return color;
}

void Pixel::setColor(std::string _color){
    color = _color;
}

std::string Pixel::mostrar(){
    std::string mostrarVar = Punto::mostrar() + ", color: " + this->color;
    return mostrarVar;
}