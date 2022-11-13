#include "Territorio.h"

Territorio::Territorio(){
    nombre = "";
    superficie = 0;
}

Territorio::Territorio(std::string _nombre, double _superficie){
    nombre = _nombre;
    superficie = _superficie;
}

std::string Territorio::getNombre() const{
    return nombre;
}

double Territorio::getSuperficie() const{
    return superficie;
}

void Territorio::setNombre(std::string _nombre){
    nombre = _nombre;
}

void Territorio::setSuperficie(double _superficie){
    superficie = _superficie;
}

std::ostream& operator << (std::ostream& salida, Territorio& territorio){
    salida << territorio.nombre << territorio.superficie;
    
    return salida;
}

std::string Territorio::obtenerDatos(){
  std::string nombrestr("Nombre: "), superficiestr(" - Superficie: "), _superficie(std::to_string(superficie));
  return nombrestr + nombre + superficiestr + _superficie + "M^2";
}
