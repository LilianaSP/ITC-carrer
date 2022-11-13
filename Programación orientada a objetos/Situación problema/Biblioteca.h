#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <vector>
#include "Video.h"

class Biblioteca{
    public:
      Biblioteca();
      void cargarDatos();
      void consultarGenero(std::string, int);
      void consultarTitulo(std::string);
      void consultarClasificacion(std::string, int);
      void consultarRating(double, int);
      void calificar(std::string, double);
      void imprime();

    private:
    // vector videos
      std::vector <Video*> repositorio;
    
};

#endif