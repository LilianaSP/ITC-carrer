#include <iostream>
#include "Figura.h"
using namespace std;

Figura::Figura(){
    x = 0;
    y = 0;
}

Figura::Figura(int _x, int _y){
    x =_x;
    y = _y;
}

int Figura::getX()const{
    return x;
}

int Figura::getY()const{
    return y;
}

void Figura::setX(int _x){
    x = _x;
}
void Figura::setY(int _x){
    x = _x;
}

string Figura::dibuja(){
    return "Soy una figura";
}

