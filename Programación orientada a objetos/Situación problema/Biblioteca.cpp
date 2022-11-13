#include "Biblioteca.h"
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Capitulo.h"
#include <iostream>
#include <fstream>
#include <cstdlib>  // para salir()
#include <string>
#include <vector>
#include <sstream>

//Inicializar la clase de biblioteca
Biblioteca::Biblioteca(){}


//método para leer archivo de texto
void Biblioteca::cargarDatos()
{
  std::ifstream archivo; //sirve para que pueda leer el archivo
  // Se declaran las variables
  char tipo;
  std::string genero, titulo, clasificacion, tituloC;
  int  oscars,temporada,duracion, numCapitulos, cantCapitulo, personas, cantTemp, duracionC;
  double rating;
    
  archivo.open("Base_de_datos.txt"); //se abre el archivo de texto y comienza la lectura

  //Condicional para que se comience leer el archivo
  if(archivo.is_open()){
     std::string linea; //se declara la variable línea que es donde se va a almacenar todos los datos de la linea
     while(getline(archivo,linea)){ //para que lea línea por línea
            std::stringstream sstr(linea);
            std::string dato; //variable donde se van a guardar cada dato 
            std::vector<std::string> datos;
            while(getline(sstr, dato,',')){ //se establece que a partir de cada coma es un dato diferente
                datos.push_back(dato); // se guarda cada dato en un vector
            }
       
       //Creamos un vector indicando donde se encuentra cada una de las variables (titulo, genero, clasificacion...) Se ponen primero los atributos en común y hasta el final los de cada clase en específico.

       //Stoi cuando es entero
       //Stod cuando es double
            tipo = datos[0].at(0); 
            titulo = datos[1];
            genero = datos[2];
            clasificacion = datos[3];
            rating = stod(datos[4]);
            personas = stoi(datos[5]);
          if(tipo == 'p'){ // se declara un método cuando detecta que el primer dato de línea es p de pelicula
            duracion = stoi(datos[6]);
            oscars = stoi(datos[7]);
              //se crea un nuevo objeto de pelicula el cual contiene los atribubtos únicos de esta clase
            repositorio.push_back(new Pelicula(titulo,genero,clasificacion,rating,personas,duracion, oscars));
          } else if(tipo == 's'){  // se declara un método cuando detecta que el primer dato de línea es s de serie
                temporada = stoi(datos[6]);
                numCapitulos = stoi(datos[7]);

            //se crea un nuevo objeto de serie el cual contiene los atribubtos únicos de esta
                Serie *serie = new Serie(titulo, genero, clasificacion, rating, personas, temporada, numCapitulos);

            //Se aplica el mismo método para leer el archivo pero ahora almacenando los datos en la variable dato2
                getline(archivo, linea);
                cantCapitulo = stoi(linea);
                std::string dato2; //definimos una nueva variable
                for(int i=1; i<=cantCapitulo; i++){
                    std::vector<std::string> datosC;
                    getline(archivo,linea);
                    std::stringstream sstr2(linea);
                    while(getline(sstr2,dato2, ','))
                    {
                        datosC.push_back(dato2);
                    }

                  //creamos los vectores que indican en qué posición de la línea de datos se encontrarán las variables buscadas
                    cantTemp = stoi(datosC[0]);
                    tituloC = datosC[1];
                    duracionC = stoi(datosC[2]);
                    Capitulo nuevoCap(cantTemp, tituloC, duracionC);
                    serie->agregaCapitulo(nuevoCap);
                }
            //Se le agrega lo anterior al repositorio que es un vector de apuntadores a video
                repositorio.push_back(serie);
            }
     
        }
        archivo.close(); //es importante cerrar el archivo
    }
}

//creamos el método que va a recorrer el repositorio y lo imprime
void Biblioteca::imprime(){
    for (int i = 0; i < repositorio.size(); i++){
        repositorio[i]->imprime(); // el imprime es polimorfico
    }    
}


//método para consultar género 
void Biblioteca::consultarGenero(std::string genero, int tipo){
  //ciclo para que recorrra el repositorio
    for (int i = 0; i < repositorio.size(); i++){
        if (tipo == 1){
            if (Pelicula* p = dynamic_cast<Pelicula*>(repositorio[i])){ // se crea el apuntador de película el cual indica que, a lo que apunte, será una película
              if (p->getGenero() == genero){
                repositorio[i] ->imprime(); //despliega el genero 
                }  
            }
                 
        }else if (tipo == 2){
            if (Serie* s = dynamic_cast<Serie*>(repositorio[i])){ //se crea el apuntador de serie el cual indica que, a lo que apunte, será una serie
                if (s->getGenero() == genero){ //despliega de género
                    repositorio[i] ->imprime(); //imprime
                }    
            }
            
        } 

    }   
}


//método para consultar título
void Biblioteca::consultarTitulo(std::string titulo){
  //ciclo para que recorrra el repositorio e imprimir un video con cierto titulo
    for (int i = 0; i < repositorio.size(); i++){
        if(repositorio[i]->getTitulo() == titulo){
            repositorio[i] ->imprime();        
        }
    }   
}


//Método para consultar clasificación
void Biblioteca::consultarClasificacion(std::string clasificacion, int tipo){
  //ciclo para que recorrra el repositorio
    for (int i = 0; i < repositorio.size(); i++){

        // Depende del tipo de video al que se le quiera buscar la clasificacion, se crea un dynamic_cast para imprimir los objetos que cumplan con ciertas caracteristicas
        if (tipo == 1){
            if (Pelicula* p = dynamic_cast<Pelicula*>(repositorio[i])){
              if (p->getClasificacion() == clasificacion){
                repositorio[i] ->imprime();
                }  
            }
                 
        }else if (tipo == 2){
            if (Serie* s = dynamic_cast<Serie*>(repositorio[i])){ 
                if (s->getClasificacion() == clasificacion){
                    repositorio[i] ->imprime();
                }    
            }
            
        } 

    }   
}

//Método para consultar Rating
void Biblioteca::consultarRating(double rating, int tipo){
  //ciclo para que recorrra el repositorio
    for (int i = 0; i < repositorio.size(); i++){
        // Depende del tipo de video al que se le quiera buscar el rating, se crea un dynamic_cast para imprimir los objetos que cumplan con ciertas caracteristicas
        if (tipo == 1){
            if (Pelicula* p = dynamic_cast<Pelicula*>(repositorio[i])){
                if (p->getRating() == rating){
                    repositorio[i] ->imprime();
                }  
            }
                 
        }else if (tipo == 2){
            if (Serie* s = dynamic_cast<Serie*>(repositorio[i])){
                if (s->getRating() == rating){
                    repositorio[i] ->imprime();
                }    
            }
            
        } 

    }   
}


//Método para calificar 
void Biblioteca::calificar(std::string titulo, double cali){
    // for para recorrer todo el repositorio
    for (int i = 0; i < repositorio.size(); i++){
        if(repositorio[i]->getTitulo() == titulo){
            *repositorio[i] + cali; // se usa la sobrecarga
        }

    }   
}

