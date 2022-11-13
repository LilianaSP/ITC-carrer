#ifndef PUNTO2D_h
#define PUNTO2D_h
#include <iostream>


//Esta es nuestra clase base para la toma de las coordenadas en x y en y
class Punto2D{
    //Declaramos los atribbutos de la clase
    //Es un punto en 2D
private:
    int x; //Coord en x
    int y; //Coord en y

public:
    Punto2D();
    Punto2D(int, int); //Pasamos los parámetros que esta recibe
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    
    //Aplicamos la función virtual para crear polimorfismo
    virtual std::string mostrar();
     //Observa que los parámetros para esta sobrecarga es referencia a ostream y apuntador a Punto
    friend std::ostream& operator<< (std::ostream &, Punto2D*&); //Sobrecarga
};
#endif