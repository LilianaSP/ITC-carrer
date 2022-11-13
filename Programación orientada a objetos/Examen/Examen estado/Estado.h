#include <iostream>

#include "Territorio.h"

#ifndef ESTADO_H
#define ESTADO_H

class Estado:public Territorio{
    private:
        double presupuesto;

    public:
        Estado();
        Estado(std::string, double, double);

        std::string obtenerDatos() override;
};

#endif