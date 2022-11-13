#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

class Persona{
    private:
        std::string nombre;
        std::string ciudad;
        int ZipCode;

    public:
        Persona(); //Inicializamos la clase
        Persona(std::string, std::string, int);
        
        //getters
        std::string getNombre() const;
        std::string getCiudad()const;
        int getZipCode()const;
        //seters
        void setNombre(std::string);
        void setCiudad(std::string);
        void setZipCode(int);
};





















#endif