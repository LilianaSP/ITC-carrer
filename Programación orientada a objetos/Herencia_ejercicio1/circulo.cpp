#include "circulo.h"
using namespace std;

Circulo::Circulo(){
    radio =1;
}

Circulo::Circulo(int _x, int _y, int r):Figura(_x,_y){
    radio = r;
}

int Circulo::getRadio() const{
    return radio;
}
void Circulo::setRadio(int r){
    radio = r;

}

string Circulo::dibuja(){
    return Figura::dibuja() + ": Circulo";
}

double Circulo::area(){
    return PI*radio*radio;
}


