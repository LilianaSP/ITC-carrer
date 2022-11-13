#ifndef PUNTO3D_h
#define PUNTO3D_h

#include "Punto.h"
#include <iostream>

class Punto3D:public Punto{
    public:
        Punto3D();
        Punto3D(int, int, int);
        int getZ() const;
        void setZ(int);
        std::string mostrar() override;
    private:
        int z;
};

#endif