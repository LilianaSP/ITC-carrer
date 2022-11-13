#ifndef TERRITORIO_H
#define TERRITORIO_H
#include <iostream>
using std::ostream;

class Territorio
{
public:
    Territorio();
    Territorio(std::string, double);
    std::string getNombre();
    double getSuperficie();

    void setNombre(std::string);
    void setSuperficie(double);

    virtual std::string obtenerDatos();
    friend ostream &operator<<(ostream &salida, Territorio *);

private:
    std::string nombre;
    double superficie;
};

#endif // TERRITORIO_H