#include "rectangulo.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo(){
    ancho = 0;
    largo = 0;
}

Rectangulo::Rectangulo(int _x, int _y, int _a, int _l):Figura(_x,_y){
    ancho = _a;
    largo = _l;
}

int Rectangulo::getAncho() const{
    return ancho;
}

int Rectangulo::getLargo() const{
    return largo;
}



string Rectangulo::dibuja(){
    return Figura::dibuja() + ": Rectangulo";
}

double Rectangulo::area_r(){
    return largo*ancho;
}

