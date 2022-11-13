#ifndef PUNTO_h
#define PUNTO_h

#include <iostream>

class Punto{
    public:
        Punto();
        Punto(int, int);
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        virtual std::string mostrar();
        friend std::ostream& operator<< (std::ostream &, Punto*&);

    private:
        int x;
        int y;
};

#endif