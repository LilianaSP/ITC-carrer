#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>
#include "Envio.h"

class Paquete: public Envio{

    private:
        double largo;
        double ancho;
        double profundidad;
        double peso;
        double costoPorKilo;



    public:
        Paquete();
        Paquete(Persona, Persona, double,double, double, double, double, double);

        //getters
        double getLargo() const;
        double getAncho() const;
        double getProfundidad() const;
        double getPeso()const;
        double getCostoPorKilo() const;
        

        //Setters
        void setLargo(double);
        void setAncho(double);
        void setProfundidad(double);
        void setPeso(double);
        void setCostoPorkilo(double);
        double calculaCosto();
        void imprime();

};











#endif 