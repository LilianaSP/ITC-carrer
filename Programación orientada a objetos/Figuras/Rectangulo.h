#include "Figura.h"
#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo:public Figura{
    public:    
        Rectangulo();
        Rectangulo(int, int, int, int);
        int getAncho() const;
        int getLargo() const;
        void setAncho(int);
        void setLargo(int);
        std::string dibuja() override;
        double area() override;

    private:
    int largo, ancho;
};

#endif