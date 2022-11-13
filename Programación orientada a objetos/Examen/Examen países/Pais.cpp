#include "Pais.h"

Pais::Pais()
{
    idioma = "Vacio";
    moneda = "Vacio";
}

Pais::Pais(std::string _nombre, double _superficie, std::string _idioma, std::string _moneda) : Territorio(_nombre, _superficie)
{
    idioma = _idioma;
    moneda = _moneda;
}

std::string Pais::obtenerDatos()
{
    return "Pais: " + Territorio::obtenerDatos() + " - Idioma: " + idioma + "- Tipo de Moneda: " + moneda;
}