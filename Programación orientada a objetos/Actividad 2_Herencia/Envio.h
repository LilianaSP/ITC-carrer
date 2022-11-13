#ifndef ENVIO_H
#define ENVIO_H
#include <iostream>
#include "Persona.h"

//realizamos la herencia de los atributos públicos de la clase persona a la clase envío
class Envio:public Persona{

    private:
        Persona remitente;
        Persona destinatario;
        double costo;
    public:
        Envio(); //inicializamos la clase
        Envio(Persona, Persona, double); //Pasamos los parámetros
        
        //Geters
        Persona getRemitente()const;
        Persona getDestinatario()const;
        double getCosto()const;


        //Settters
        void setRemitente(Persona);
        void setDestinatario(Persona);
        void setCosto(double);

        double calculaCosto();
        void imprime();




};

#endif










