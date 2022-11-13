#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"
#include <iostream>

class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(std::string, std::string, std::string, int,int, std::string, double);

        //getters
        int getOscars() const;
        std::string getFormatoGrabacion() const;
        double getDuracion() const;

        //setters
        void setOscars(int);
        void setFormatoGrabacion(std::string);
        void setDuracion(double);
        void imprime() override;
    
    private:
        int oscars;
        std::string formatoGrabacion; 
        double duracion;
};

#endif