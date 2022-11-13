#include <iostream>
#include "Paquete.h"

Paquete::Paquete()
{
    largo = 0;
    ancho = 0;
    profundidad = 0;
    peso = 0;
    costoPorKilo = 0;
}

Paquete::Paquete(Persona _remitente, Persona _destinatario, double _costo, double _largo, double _ancho, double _profundidad, double _peso, double _costoPorKilo): Envio(_remitente, _destinatario, _costo)
{
    largo = _largo;
    ancho = _ancho;
    peso = _peso;
    profundidad = _profundidad;
    costoPorKilo = _costoPorKilo;
}

double Paquete::getLargo()const
{
    return largo;
}

double Paquete::getAncho()const
{
    return ancho;
}

double Paquete::getProfundidad()const
{
    return profundidad;
}

double Paquete::getPeso()const
{
    return peso;
}

double Paquete::getCostoPorKilo()const
{
    return costoPorKilo;
}

void Paquete::setLargo(double _largo)
{
    largo = _largo;
}

void Paquete::setAncho(double _ancho)
{
    ancho = _ancho;
}

void Paquete::setProfundidad(double _profundidad)
{
    profundidad = _profundidad;
}

void Paquete::setPeso(double _peso)
{
    peso = _peso;
}

void Paquete::setCostoPorkilo(double _costoPorKilo)
{
    costoPorKilo = _costoPorKilo;
}

double Paquete::calculaCosto()
{
    return costoPorKilo * peso + Envio::calculaCosto();
}

void Paquete::imprime()
{
    std::cout<< "DATOS DEL ENVÍO DEL PAQUETE"<<std::endl;
    std::cout<<"++++++++++++++++++++++++++++++++"<<std::endl;
    Envio::imprime(); //lamamos a la clase envío para que se visualice su método de imprimir
    std::cout<<"DATOS DEL PAQUETE"<<std::endl;
    std::cout<<"Largo en cm: "<<largo<<" cm"<<std::endl;
    std::cout<<"Ancho en cm: "<<ancho<<" cm"<<std::endl;
    std::cout<<"Profundidad en cm:"<<profundidad<<" cm"<<std::endl;
    std::cout<<"Peso en Kg: "<<peso<<" Kg"<<std::endl;
    std::cout<<"Costo por Kilo: "<<costoPorKilo<< " $"<<std::endl;
}