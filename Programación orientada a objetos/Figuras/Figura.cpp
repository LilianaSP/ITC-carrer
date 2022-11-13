#include "Figura.h"

Figura::Figura(){
    this-> x = 0;
    this-> y = 0;
}

Figura::Figura(int x,int y){
    this -> x = x;
    this -> y = y;
}
int Figura::getX() const{
    return this-> x;
}

int Figura::getY() const{
    return this-> y;
}
void Figura::setX(int x){
    this-> x = x;
}
void Figura::setY(int y){
    this-> y = y;
}
std::string Figura::dibuja(){
    return "\nSoy una figura";
}
