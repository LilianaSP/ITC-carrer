#include <iostream>
#include "Punto.h"
#include "Punto3D.h"
#include "Pixel.h"
#include <vector>

using namespace std;

int main(){
    std::vector<Punto*> puntos;

    puntos.push_back(new Punto(2, 4));
    puntos.push_back(new Punto3D(1, 2, 5));
    puntos.push_back(new Punto3D(3, 2, -5));
    puntos.push_back(new Pixel(5, 3, "FFCCCC"));
    puntos.push_back(new Pixel(2, 4, "FF9966"));

    for (int i = 0; i < puntos.size(); i++)
    {
        cout << puntos[i] << endl;
    }

    return 0;
}