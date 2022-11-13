#include "Persona.h"
#include <iostream>

Persona::Persona()
{
    nombre = "INICIALIZARCONSTRING";
    ciudad = "INICIALIZARCONSTRING";
    ZipCode = 000000000;
}

Persona::Persona(std::string _nombre, std::string _ciudad, int _ZipCode)
{
    nombre = _nombre;
    ciudad = _ciudad;
    ZipCode = _ZipCode;
}

std::string Persona::getNombre()const
{
    return nombre;
}
std::string Persona::getCiudad()const
{
    return ciudad;
}

int Persona::getZipCode()const
{
    return ZipCode;
}

void Persona::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

void Persona::setCiudad(std::string _ciudad)
{
    ciudad = _ciudad;
}

void Persona::setZipCode(int _ZipCode)
{
    ZipCode = _ZipCode;
}
