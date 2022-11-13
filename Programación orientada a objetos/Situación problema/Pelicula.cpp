#include "Pelicula.h"
#include <iostream>


//Se inicializa los atribubtos de la clase película
Pelicula::Pelicula()
{
    oscars = 0;
    duracion = 0;
}


//atributos que recibbe la clase película junto con herencia de la clase video 
Pelicula::Pelicula(std::string _titulo, std::string _genero, std::string _clasificacion, double _rating, int _personas, int _duracion, int _oscars):Video(_titulo, _genero, _clasificacion, _rating, _personas)

{
    duracion = _duracion;
    oscars = _oscars;
}

//getters
int Pelicula::getOscars() const
{
    return oscars;
}

int Pelicula::getDuracion() const
{
    return duracion;
}

//setters
void Pelicula::setOscars(int _oscars)
{
    oscars = _oscars;
}

void Pelicula::setDuracion(int _duracion)
{
    duracion = _duracion;
}


//imprime los datos de película
void Pelicula::imprime()
{
    std::cout << "\nDATOS DE LA PELÍCULA" <<std::endl;
    std::cout << "++++++++++++++++++++++++++" << std::endl;
    Video::imprime();
    std::cout<<"Duracion de la pelicula: " << getDuracion() << " minutos"<< std::endl;
    std::cout<<"Cantidad de Oscars de la pelicula: " << getOscars() << std::endl;
 
}