#include "Biblioteca.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Capitulo.h"
#include <iostream>
#include <fstream>
#include <cstdlib>  // para salir()
#include <string>
#include <vector>
#include <sstream>

Biblioteca::Biblioteca()
{
  
}

void Biblioteca::cargarDatos()
{
  std::ifstream archivo;
  char tipo;
  std::string genero, titulo, clasificacion, formatoGrabacion;
  int rating, oscars,temporada, numCapitulo, personas;
  double duracion;
  archivo.open("Base_de_datos.txt"); //abrimos el archivo txt

  //condicional para que lea las lineas del archivo
  if(archivo.is_open()){
    std::string linea;
    while(getline(archivo,linea)){
      std::stringstream sstr(linea);
      std::string dato;
      std::vector<std::string> datos;
      while(getline(sstr, dato,",")){
        datos.push_back(dato);
      }
      tipo = datos[0].at(0);
      titulo = datos[1];
      duracion = stoi(datos[2]);
      genero = datos[3];
      clasificacion = datos[4];
      rating = stoi(datos[5]);
      if(tipo == 'p'){
        personas = stoi(datos[6]);
        // inicial, titulo, duracion, genero, clasificacion, rating, personas 
        repositorio.push_back(new Pelicula(titulo,duracion,genero,clasificacion,rating, personas));
      }
      else if(tipo == 's'){
        // inicial, titulo, temporadas, episodios, genero, clasificacion, raiting, personas
        //Serie *s = new Serie(titulo,temporada, numCapitulo, genero, clasificacion,rating,personas);
        std::vector<Capitulo> s;
        getline(archivo, linea);
        numCapitulo = stoi(linea);
        temporada = stoi(linea);
        std::string dato2;
        for(int i=1; i<=numCapitulo; i++){
          std::vector<std::string> datosC;
          getline(archivo,linea);
          std::stringstream sstr2(linea);
          while(getline(sstr2,dato2, ','))
          {
            datosC.push_back(dato2);
          }
          // inicial, temporada, titulo, duracion
          temporada = stoi(datosC[1]);
          titulo = datos[2];
          duracion = stoi(datos[3]);
          //Capitulo nuevo(titulo,temporada);
          //s->agregaCapitulo(nuevo);
          s.push_back(Capitulo(titulo,temporada));
        }
        repositorio.push_back(new Serie(genero, titulo, clasificacion,rating, temporada, numCapitulo, personas, s));

      }
     
    }
    archivo.close();
  }
}
