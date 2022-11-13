#include <iostream>
#include "Serie.h"

  
Serie::Serie()
{
    temporada = 0;
    numCapitulo = 0;
}


Serie::Serie(std::string _genero, std::string _titulo, std::string _clasificacion, int _rating, int _temporada, int _numcapitulo):Video(_genero, _titulo, _clasificacion, _rating)
{ 
    temporada = _temporada;
    numCapitulo = _numcapitulo;
}


int Serie::getTemporada() const
{
    return temporada;
}

int Serie::getNumCapitulo() const
{
    return numCapitulo; 
}

void Serie:: setTemporada(int _temporada)
{
    temporada = _temporada;
}

void Serie:: setNumCapitulo(int _numcapitulo)
{
    numCapitulo = _numcapitulo;
}


void Serie::imprime ()
{
    Video::imprime(); 
    std::cout << "DATOS DE LA SERIE" <<std::endl;
    std::cout<< "Temporada: " << getTemporada() << std::endl;
    std::cout << "Capítulo: "<< getNumCapitulo() << std::endl;
    std::cout << "+++++++++++++++++++++++++" << std::endl;

  for (int i = 0; i<capitulo.size(); i++ )
    {
      capitulo[i].imprime(); //implementar la función imprime en capítulos
    }
}