#include <iostream>

#include "Territorio.h"

#ifndef PAIS_H
#define PAIS_H

class Pais:public Territorio{
    private:
        std::string idioma, moneda;

    public:
        Pais();
        Pais(std::string, double, std::string, std::string);

        std::string obtenerDatos() override;
};

#endif