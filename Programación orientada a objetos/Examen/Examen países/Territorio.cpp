#include <iostream>
#include "Territorio.h"
#include <string.h>

Territorio::Territorio()
{
    nombre = "XXXXXX";
    superficie = 0;
}

std::string Territorio::getNombre()
{
    return nombre;
}
double Territorio::getSuperficie()
{
    return superficie;
}

void Territorio::setNombre(std::string _nombre)
{
    nombre = _nombre;
}
void Territorio::setSuperficie(double _superficie)
{
    superficie = _superficie;
}

Territorio::Territorio(std::string _nombre, double _superficie)
{
    nombre = _nombre;
    superficie = _superficie;
}

std::string Territorio::obtenerDatos()
{
    // return nombre + " - " + std::to_string(superficie) + " m^2";
    return "Territorio: " + nombre + " - " + std::to_string(superficie) + " m^2";
}

ostream &operator<<(ostream &salida, Territorio *otro) // friend
{
    salida << otro->obtenerDatos() << std::endl;
    return salida;
}