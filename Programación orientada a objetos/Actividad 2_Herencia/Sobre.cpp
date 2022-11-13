#include "Sobre.h"
#include <iostream>

Sobre::Sobre()
{
    largosobre = 0;
    anchosobre = 0;
    costoAdicional = 0;
}
Sobre::Sobre(Persona _remitente, Persona _destinatario, double _costo, double _largosobre, double _anchosobre) : Envio(_remitente, _destinatario, _costo)
{
    largosobre = _largosobre;
    anchosobre = _anchosobre;
    costoAdicional = 0;
}

double Sobre::getLargoSobre()const
{
    return largosobre;
}

double Sobre::getAnchoSobre()const
{
    return anchosobre;
}

double Sobre::getCostoAdicional() const
{
    return costoAdicional;
}

void Sobre::setLargoSobre(double _largosobre)
{
    largosobre = _largosobre;
}

void Sobre::setAnchoSobre(double _anchoSobre)
{
    anchosobre = _anchoSobre;
}

void Sobre::setCostoAdicional(double _costoAdicional)
{
    costoAdicional = _costoAdicional;
}

double Sobre::calculaCosto() //Aplicamos la condición dada sobre el costo del sobre
{
    if ((largosobre >= 30 && anchosobre >=25)|| (anchosobre >=30 && largosobre >=25)) 
    {
        costoAdicional = 20;
    }
    return costoAdicional + Envio::calculaCosto();
}

void Sobre::imprime()
{
    std::cout<<"DATOS DE ENVÍO"<<std::endl;
    std::cout<<"+++++++++++++++++++++++++++"<<std::endl;
    Envio::imprime();
    std::cout<< "DATOS DEL SOBRE"<<std::endl;
    std::cout<< "Largo del sobre en cm: "<<largosobre<< " cm"<<std::endl;
    std::cout<< "Ancho del sobre en cm: "<<anchosobre<< " cm"<<std::endl;
    std::cout<< "Costo adicional: "<<costoAdicional<< " $"<<std::endl;

}