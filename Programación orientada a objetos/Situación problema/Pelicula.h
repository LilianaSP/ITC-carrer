#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"
#include <iostream>

class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(std::string, std::string, std::string, double,int, int, int);

        //getters
        int getOscars() const;
        int getDuracion() const;

        //setters
        void setOscars(int);
        void setDuracion(int);
        void imprime() override; //funcion polimorfica
    private:
        int oscars;
        int duracion;
};

#endif