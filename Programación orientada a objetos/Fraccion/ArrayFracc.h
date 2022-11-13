#ifndef ARRAYFRACC_H
#define ARRAYFRACC_H
#include <iostream>
#include <vector> 
#include "Fraccion.h"

class ArrayFracc{
    public:
        ArrayFracc();
        void agregaFraccion(Fraccion &);
        Fraccion& perator[](int);
    private:
        std::vector<Fraccion> fracciones; 
};

#endif //ARRAYFRACC_H