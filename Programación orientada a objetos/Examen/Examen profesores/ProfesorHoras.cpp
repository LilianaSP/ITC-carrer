#include "ProfesorHoras.h"

//constructores
ProfesorHoras::ProfesorHoras(){
    horas = 0;
}

ProfesorHoras::ProfesorHoras(int _numNomina, std::string _departamento, double _sueldoBase, int _horas):Profesor(_numNomina, _departamento, _sueldoBase){
    horas = _horas;
}

//adicionales
double ProfesorHoras::calculaSueldoNeto(){
    double sueldoNeto = (this->horas * Profesor::getSueldoBase()) * .85;
    // por .85 para descontar el 15 porciento
    return sueldoNeto;
}