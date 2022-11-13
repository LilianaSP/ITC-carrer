#include <iostream>
#include "Punto2D.h"
#include "Punto3D.h"
#include "Pixel.h"
#include <vector>

using namespace std;

int main(){

    //Creamos un vector llamado de las coordenadas de los puntos de acuerdo las indicaciones que se nos piden
    vector<Punto2D*> coordPuntos;

    //utilizamos push_back para la reación de los objetos a como se pide
    //Creamos un obejto punto
    coordPuntos.push_back(new Punto2D(7,10));

    //creamos dos puntos en 3D
    coordPuntos.push_back(new Punto3D(7,10, 4));
    coordPuntos.push_back(new Punto3D(-6,13, 8));

    //Creamos los dos obejtos de pixel
    coordPuntos.push_back(new Pixel(3,10, "FF9966"));
    coordPuntos.push_back(new Pixel(-5,2, "00FF36"));

    //Creamos un for para que se recorra el arreglo de los datos
    for (int i = 0; i<coordPuntos.size(); i++)
    {
        cout << coordPuntos[i] << endl;
    }


return 0;

}
