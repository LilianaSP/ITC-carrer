#include <iostream>
#include "Envio.h"
#include "Paquete.h"
#include "Sobre.h"
using namespace std;

int main()
{
    //Clase persona recibe, nombre, ciudad, código postal
    Persona p1("Liliana Solorzano Perez", "Guadalajara", 45019);
    Persona p2("Ximena Alvarez Gomez", "Michoacán", 4134);

    //clase envio recibe persona remitente (p1) y persona destinatario (p2), costo del envío
    Envio envio1(p1,p2,230.42);

    //clase paquete recibe remitente, destinatario, calculacosto, largo, ancho,profundidad, peso, costo por kilo
    Paquete paquete1(p1, p2,envio1.calculaCosto(), 40.6, 60.67, 40.6, 3.5, 25.99);
    Sobre sobre1(p1, p2, envio1.calculaCosto(), 24.5, 32.5);
    // envio1.imprime();
    // sobre1.imprime();
    cout << "- ENVIO Y PAQUETE - \n"<< endl;
    paquete1.imprime();
    cout << "- - - - - - - - - - - - - - " << endl;
    cout << "Costo del envio: $" << envio1.calculaCosto() << endl;
    cout << "- - - - - - - - - - - - - - " << endl;
    cout << "Costo del paquete: $" << paquete1.calculaCosto() << endl;
    cout << "- - - - - - - - - - - - - - " << endl;
    cout << "Costo del sobre + costo adicional: $" << sobre1.calculaCosto() << endl;
    
}