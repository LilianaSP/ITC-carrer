#ifndef PIXEL_h
#define PIXEL_h

#include "Punto.h"
#include <iostream>

class Pixel:public Punto{
    public:
        Pixel();
        Pixel(int, int, std::string);
        std::string getColor() const;
        void setColor(std::string);
        std::string mostrar() override;
    private:
        std::string color;
};

#endif