#include <iostream>
#include "Serie.h"


//Se inicializa la clase serie y sus atributos
Serie::Serie()
{
    temporada = 0;
    numCapitulo = 0;
}

//atributos de serie y herencia de la clase video
Serie::Serie(std::string _titulo, std::string _genero, std::string _clasificacion, double _rating, int _personas, int _temporada,int _numcapitulo):Video(_titulo,  _genero,  _clasificacion,  _rating,  _personas)

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

// funcion para agregar un capitulo al vector de capitulos
void Serie::agregaCapitulo(Capitulo& cap)
{
    capitulo.push_back(cap);
}


//Formato de imprime para serie
void Serie::imprime ()
{
    std::cout << "\nDATOS DE LA SERIE" <<std::endl;
    std::cout << "++++++++++++++++++++++++++" << std::endl;
    Video::imprime(); 
    std::cout<< "Cantidad de Temporadas: " << getTemporada() << std::endl;
    std::cout << "Total de Capítulos: "<< getNumCapitulo() << std::endl;

  //Vector para recorrer los capítlos
  for (int i = 0; i<capitulo.size(); i++)
    {
      capitulo[i].imprime();  
    } 
}