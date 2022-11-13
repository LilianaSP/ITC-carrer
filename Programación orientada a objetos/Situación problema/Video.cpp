
#include "Video.h"
#include <iostream>
#include <iomanip>

Video::Video()
{
    genero = "XXXXXXXXXXX";
    titulo = "XXXXXXXXXXXX";
    clasificacion = "XXXXXXXXXXXXX";
    rating = 0.0;
    personas = 0;
}

//Parámetros que recibe video, declarados en el .h
Video::Video(std::string _titulo, std::string _genero, std::string _clasificacion, double _rating, int _personas)
{
    titulo = _titulo;
    genero = _genero;
    clasificacion = _clasificacion;
    rating = _rating;
    personas = _personas;
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

int Video::getPersonas() const
{
    return personas;
}

double Video::getRating() const
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

void Video::setPersonas(int _personas)
{
    personas = _personas;
}

void Video::setRating(double _rating)
{
    rating = _rating;
}


//Formato de impresión para los atributos de la clase Video
void Video::imprime()
{
    std::cout<< "Título: " << getTitulo() << std::endl;  
    std::cout<< "Genero: " << getGenero() << std::endl;
    std::cout << "Clasificación: " << getClasificacion() <<std:: endl;
    std::cout << "Rating: " << std::fixed<<std::setprecision(3)<<getRating() <<std:: endl;
}

// Sobrecarga de operador +
void Video::operator + (const double nR){
    double nRating = (rating*personas + nR) / (personas + 1);
    setRating(nRating);
    setPersonas((personas+1));
}
