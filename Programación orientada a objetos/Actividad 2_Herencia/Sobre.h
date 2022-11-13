#ifndef SOBRE_H
#define SOBRE_H
#include <iostream>
#include "Envio.h"


class Sobre:public Envio{

    private:
        double largosobre;
        double anchosobre;
        double costoAdicional;

    public:
        Sobre();
        Sobre(Persona,Persona,double, double, double);
        

        //Getters
        double getLargoSobre()const;
        double getAnchoSobre()const;
        double getCostoAdicional()const;

        //Setters

        void setLargoSobre(double);
        void setAnchoSobre(double);
        void setCostoAdicional(double);
        double calculaCosto();
        void imprime();


};

#endif