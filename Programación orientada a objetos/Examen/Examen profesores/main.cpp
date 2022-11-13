#include <vector>
#include <iostream>

#include "ProfesorTiempoCompleto.h"
#include "ProfesorHoras.h"


int main(){

//creamos vector
    std::vector <Profesor*> profesores;

//lo llenamos con objetos
    profesores.push_back(new ProfesorHoras(1, "Negocios", 1000, 80));
    profesores.push_back(new ProfesorTiempoCompleto(2, "Ingenierias", 2000, 20));
    profesores.push_back(new ProfesorHoras(3, "Humanidades", 800, 70));

    ProfesorHoras prof1(4, "Ingenierias", 785, 80);

//Imprimimos los sueldos
    std::cout << "---------------------------------\n\n";
    std::cout << "SUELDOS: " << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << "Profesor en la posicion: " << i << std::endl;
        std::cout << (*profesores[i]).calculaSueldoNeto() << std::endl;
    }

    std::cout << "prof 1: \n" << prof1.calculaSueldoNeto() << std::endl;
    std::cout << "---------------------------------\n\n";

//recorremos el arreglo

    for(int i = 0; i < 3; i++){
        if(prof1 < (*profesores[i])){
            std::cout << "El profesor en la posicion <" << i << "> gana MAS que el prof1!" << std::endl;
        }
        else{
            std::cout << "El profesor en la posicion <" << i << "> gana MENOS que el prof1!" << std::endl;
        }
    }




    return 0;
}