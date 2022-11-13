#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula()
{
    oscars = 0;
    formatoGrabacion = "XXXXX";
    duracion = 0;
}

Pelicula::Pelicula(std::string _genero, std::string _titulo, std::string _clasificacion, int _rating, int _oscars ,std::string _formatoGrabacion, double _duracion):Video(_genero, _titulo, _clasificacion, _rating)
{
    oscars = _oscars;
    formatoGrabacion = _formatoGrabacion;
    duracion = _duracion;   
}

//getters
int Pelicula::getOscars() const
{
    return oscars;
}

std::string Pelicula::getFormatoGrabacion() const
{
    return formatoGrabacion;
}

double Pelicula::getDuracion() const
{
    return duracion;
}

//setters
void Pelicula::setOscars(int _oscars)
{
    oscars = _oscars;
}

void Pelicula::setFormatoGrabacion(std::string _formatoGrabacion)
{
    formatoGrabacion = _formatoGrabacion;   
}

void Pelicula::setDuracion(double _duracion)
{
    duracion = _duracion;
}

void Pelicula::imprime()
{
    Video::imprime();
    std::cout << "DATOS DE LA PELÍCULA" <<std::endl;
    std::cout << "++++++++++++++++++++++++++" << std::endl;
    std::cout<<"Formato de grabacion: " << getFormatoGrabacion() << std::endl;
    std::cout<<"Duracion de la pelicula: " << getDuracion() << std::endl;
    std::cout<<"Cantidad de Oscars de la pelicula: " << getOscars() << std::endl;
    std::cout<<"+++++++++++++++++++++++++++++++++" << std::endl;
}