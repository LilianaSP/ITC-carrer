#include <iostream>
#include "Envio.h"

Envio::Envio(){
    costo = 0;
    
}

Envio::Envio(Persona _remitente,Persona _destinatario, double _costo)
{
    remitente = _remitente;
    destinatario = _destinatario;
    costo = _costo;
}

Persona Envio::getRemitente()const
{
    return remitente;
}

Persona Envio::getDestinatario() const
{
    return destinatario;
}

double Envio::getCosto() const
{
    return costo;
}

void Envio::setRemitente(Persona _remitente)
{
    remitente = _remitente;
}

void Envio::setDestinatario(Persona _destinatario)
{
    destinatario = _destinatario;
}

void Envio::setCosto(double _costo)
{
    costo = _costo;
}

double Envio::calculaCosto()
{
    return costo;
}

void Envio::imprime()
{
    std::cout<<"Datos del Remitente"<<std::endl;
    std::cout<<"Nombre del Remitente: "<<remitente.getNombre()<<std::endl;
    std::cout<<"Origen del Remitente: "<<remitente.getCiudad()<<std::endl;
    std::cout<<"C.P. del remitente: "<<remitente.getZipCode()<<std::endl;
    std::cout<< "++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    std::cout<<"Datos del Destinatario"<<std::endl;
    std::cout<<"Nombre del Destinatario: "<<destinatario.getNombre()<<std::endl;
    std::cout<<"Origen del Destinatario: "<<destinatario.getCiudad()<<std::endl;
    std::cout<<"C.P. del destinatario: "<<destinatario.getZipCode()<<std::endl;
    std::cout<<"+++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    
}