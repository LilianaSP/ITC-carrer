//GUARDAS
#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
using std::ostream;

class Profesor{
    public:
    //constructores
    Profesor();
    Profesor(int, std::string, double);

    //getters
    double getSueldoBase();

    //setters
    void setSueldoBase(double);

    //adicionales
    virtual double calculaSueldoNeto() = 0; //virtual puro
    bool operator< ( Profesor&); // con * o &


    private:
    //atributos
        int numNomina;
        std::string departamento;
        double sueldoBase;
};

#endif //PROFESOR_H