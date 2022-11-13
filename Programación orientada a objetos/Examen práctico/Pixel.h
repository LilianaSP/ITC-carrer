#ifndef PIXEL_h
#define PIXEL_h
#include "Punto2D.h"
#include <iostream>

class Pixel:public Punto2D{
    //Definimos sus atributos
    private:
        std::string color;

    public: 
        Pixel();
        Pixel(int, int, std::string); //se le pasan los parámetros de la clase punto y al último el atributo de pixel
        std::string getColor() const; //definimos el getter del color de nuestro pixel
        void setColor(std::string); 
        std::string mostrar() override;
};

#endif