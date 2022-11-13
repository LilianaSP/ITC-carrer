#include "Circulo.h"


Circulo::Circulo(){
    radio = 1;
}

Circulo::Circulo(int x, int y, int radio):Figura(x,y){
    this-> radio = radio;
}

int Circulo::getRadio() const{
    return this -> radio;
}

void Circulo::setRadio(int radio){
    this-> radio = radio;
}

std::string Circulo::dibuja(){
    return Figura::dibuja() + ": Circulo";
}

double Circulo::area(){
    return Pi*radio*radio;
}
double Circulo::circunferencia(){
    return Pi*(radio*2);
}