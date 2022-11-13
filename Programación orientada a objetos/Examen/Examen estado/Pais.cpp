#include "Pais.h"

Pais::Pais(){
  idioma =""; 
  moneda ="";
}

Pais::Pais(std::string _nombre, double  _superficie, std::string _idioma, std::string _moneda):Territorio(_nombre, _superficie){
  idioma = _idioma;
  moneda = _moneda;
}

std::string Pais::obtenerDatos(){
  std::string idiomastr(" - Idioma: "), monedastr(" - Moneda: ");
  return Territorio::obtenerDatos() + idiomastr + idioma + monedastr + moneda;
}