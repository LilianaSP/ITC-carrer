
#include "Video.h"
#include <iostream>

Video::Video()
{
  genero = "XXXXXXXXXXX";
  titulo = "XXXXXXXXXXXX";
  clasificacion = "XXXXXXXXXXXXX";
  rating = 000000;
}

Video::Video(std::string _genero, std::string _titulo, std::string _clasificacion, int _rating)
{
  
  genero = _genero;
  titulo = _titulo;
  clasificacion = _clasificacion;
  rating = _rating;
}

//getters

std::string Video::getGenero() const
{
  return genero;
}

std::string Video::getTitulo() const
{
  return titulo;
}

std::string Video::getClasificacion() const
{
  return clasificacion;
}

int Video::getRating() const
{
    return rating;
}

//setters

void Video::getGenero(std::string _genero)
{
    genero = _genero;
}

void Video::setTitulo(std::string _titulo)
{
    titulo = _titulo;
}

void Video::setClasificacion(std::string _clasificacion)
{
    clasificacion = _clasificacion;
}
void Video::setRating(int _rating)
{
    rating = _rating;
}

void Video::imprime()
{
  
  std::cout<<"STREAM DE VIDEOS"<<std::endl;
  std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
  std::cout<< "Genero: " << getGenero() << std::endl;
  std::cout<< "Título: " << getTitulo() << std::endl;
  std::cout << "Clasificación: " << getClasificacion() <<std:: endl;
  std::cout<< "+++++++++++++++++++++++++++++"<< std::endl;
}

