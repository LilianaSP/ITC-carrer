#include "Capitulo.h"
#include <iostream>


// se inicializa la clase
Capitulo::Capitulo()
{
    nombreCapitulo = "XXXXXXXXXXXX";
    temporada = 00000000;
    duracion = 000;
}

//se declaran los atributos de la clase capítulo
Capitulo::Capitulo(int _temporada, std::string _nombreCapitulo, int _duracion)
{
    nombreCapitulo = _nombreCapitulo;
    temporada = _temporada;
    duracion = _duracion;
}

//getters

std::string Capitulo::getNombreCapitulo() const
{
  return nombreCapitulo;
}

int Capitulo::getTemporada() const
{
  return temporada;
}

int Capitulo::getDuracion() const
{
  return duracion;
}


//setters

void Capitulo::setNombreCapitulo(std::string _nombreCapitulo)
{
  nombreCapitulo = _nombreCapitulo;
}

void Capitulo::setTemporada(int _temporada)
{
  temporada = _temporada;
}

void Capitulo::setDuracion(int _duracion)
{
  duracion = _duracion;
}

//formato de imprime para los capítulos de una serie
void Capitulo::imprime()
{
    std::cout<< " - Temporada: "<< getTemporada() << std::endl;
    std::cout<< " + Capítulo: "<< getNombreCapitulo()<<std::endl;
    std::cout<< " + Duracion: "<< getDuracion() << " minutos"<< std::endl;

}
