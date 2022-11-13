#include <iostream>
#include <vector>
#include "Pais.h"
#include "Estado.h"
#include "Territorio.h"

using namespace std;

// Diego Partida Romero
// A01641113
// Examen Practico 9 de junio del 2022

int main()
{
    cout << "\nEXAMEN PRACTICO\nDIEGO PARTIDA A01641113\n- - - - - - - - - - - - - - - - - -" << endl;
    Territorio *territorios[5];
    territorios[0] = new Territorio("México", 843274.218);
    territorios[1] = new Pais("USA", 872342.258957, "Ingles", "USD");
    territorios[2] = new Pais("Alemania", 46526.49284, "Aleman", "Euros");
    territorios[3] = new Estado("Jalisco", 2538.14879, 8746211.343);
    territorios[4] = new Estado("Arizona", 14678.24761, 13187648.356);

    for (int i = 0; i < size(territorios); i++)
    {
        // cout << "Posicion [" << i << "] del arreglo: " << territorios[i]; Impresion opcional
        cout << i + 1 << ". " << territorios[i] << endl;
    }
}