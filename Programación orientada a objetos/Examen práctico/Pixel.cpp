#include "Pixel.h"
#include <iostream>
#include <string>
#include <sstream>


Pixel::Pixel(){
    color = "XXXXXXXX"; //el color del pixel es un string
}

Pixel::Pixel(int _x, int _y, std::string _color):Punto2D(_x, _y){
    color = _color;
}

std::string Pixel::getColor() const{
    return color;
}

void Pixel::setColor(std::string _color){
    color = _color;
}

std::string Pixel::mostrar(){
    std::string imprimePixel = Punto2D::mostrar() + " +Color del Pixel : " + color; //concatenación
    
    return imprimePixel;
}