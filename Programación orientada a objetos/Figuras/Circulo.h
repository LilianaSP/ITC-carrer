#include "Figura.h"
#ifndef CIRCULO_H
#define CIRCULO_H

const static double Pi = 3.14159;
class Circulo:public Figura{
    public:    
        Circulo();
        Circulo(int, int, int);
        int getRadio() const;
        void setRadio(int);
        std::string dibuja() override;
        double area() override;
        double circunferencia();

    private:
    int radio;
};

#endif