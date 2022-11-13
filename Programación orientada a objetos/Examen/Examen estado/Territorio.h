#include <iostream>

#ifndef TERRITORIO_H
#define TERRITORIO_H

class Territorio{
    private:
        std::string nombre;
        double superficie;

    public:
        Territorio();
        Territorio(std::string, double);

        std::string getNombre() const;
        double getSuperficie() const;

        void setNombre(std::string);
        void setSuperficie(double);

        virtual std::string obtenerDatos();

        friend std::ostream& operator << (std::ostream &, Territorio&);
};

#endif