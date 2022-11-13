#ifndef PROFESORHORAS_H
#define PROFESORHORAS_H

#include "Profesor.h"

#include <iostream>
using std::ostream;

class ProfesorHoras: public Profesor{
    public:
    //constructores
    ProfesorHoras();
    ProfesorHoras(int, std::string, double, int);

    //adicionales
    double calculaSueldoNeto() override;

    private:
    //atributos
    int horas;
};

#endif // PROFESORHORAS_H
