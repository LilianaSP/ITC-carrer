#include "ProfesorTiempoCompleto.h"

//constructores
ProfesorTiempoCompleto::ProfesorTiempoCompleto(){
    porcentajeImp = 0;
}

ProfesorTiempoCompleto::ProfesorTiempoCompleto(int _numNomina, std::string _departamento, double _sueldoBase, int _porcentajeImp):Profesor(_numNomina, _departamento, _sueldoBase){
    porcentajeImp = _porcentajeImp;
}

//adicionales
double ProfesorTiempoCompleto::calculaSueldoNeto(){
    double sueldoNeto = Profesor::getSueldoBase() - Profesor::getSueldoBase() / 100 * this->porcentajeImp;
    return sueldoNeto;
}