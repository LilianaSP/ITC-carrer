#ifndef PAIS_H
#define PAIS_H
#include <iostream>
#include "Territorio.h"

class Pais : public Territorio
{

public:
    Pais();
    Pais(std::string, double, std::string, std::string);

    std::string obtenerDatos() override;

private:
    std::string idioma;
    std::string moneda;
};

#endif // PAIS_H