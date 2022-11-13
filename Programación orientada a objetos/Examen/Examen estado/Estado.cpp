#include "Estado.h"

Estado::Estado(){
    presupuesto = 0;
}

Estado::Estado(std::string _nombre, double _superficie, double _presupuesto):Territorio(_nombre, _superficie){
    presupuesto = _presupuesto;
}

std::string Estado::obtenerDatos(){
  std::string presupuestostr(" - Presupuesto: "), _presupuesto(std::to_string(presupuesto));  
  return Territorio::obtenerDatos() + presupuestostr + _presupuesto;
} 