#ifndef PROFESORTIEMPOCOMPLETO_H
#define PROFESORTIEMPOCOMPLETO_H

#include "Profesor.h"

#include <iostream>
using std::ostream;

class ProfesorTiempoCompleto: public Profesor{
    public:
    //constructores
    ProfesorTiempoCompleto();
    ProfesorTiempoCompleto(int, std::string, double, int);

    //adicionales
    double calculaSueldoNeto() override;

    private:
    //atributos
        int porcentajeImp;
};

#endif //PROFESORTIEMPOCOMPLETO_H