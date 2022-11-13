#include "Punto3D.h"
#include <string>
#include <sstream>

Punto3D::Punto3D(){
    z = 0;
}

Punto3D::Punto3D(int _x, int _y, int _z):Punto(_x, _y){
    z = _z;
}

int Punto3D::getZ() const{
    return z;
}

    void Punto3D::setZ(int _z){
    z = _z;
}

std::string Punto3D::mostrar(){
    std::ostringstream oss;
    oss << Punto::mostrar() << ", z: "  << this->z;
    std::string mostrarVar = oss.str();
    return mostrarVar;
}