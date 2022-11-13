#include  "Profesor.h"

//constructores
Profesor::Profesor(){
    numNomina = 0;
    departamento = "";
    sueldoBase = 0;
}
Profesor::Profesor(int _numNomina, std::string _departamento, double _sueldoBase){
    numNomina = _numNomina;
    departamento = _departamento;
    sueldoBase = _sueldoBase;

}

//getters
double Profesor::getSueldoBase(){
    return sueldoBase;

}

//setters
void Profesor::setSueldoBase(double _sueldoBase){
    sueldoBase = _sueldoBase;

}

//adicionales
bool Profesor::operator< ( Profesor& prof){
    if (this->calculaSueldoNeto() < prof.calculaSueldoNeto()){
        return true;
    }
    return false;

} // con * o &

