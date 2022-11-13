#ifndef ESTADO_H
#define ESTADO_H
#include <iostream>
#include "Territorio.h"

class Estado : public Territorio
{

public:
    Estado();
    Estado(std::string, double, double);

    std::string obtenerDatos() override;

private:
    double presupuesto;
};

#endif // ESTADO_H