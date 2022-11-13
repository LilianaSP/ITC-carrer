#include "Territorio.h"
#include "Estado.h"
#include "Pais.h"

using namespace std;

int main(){
    Territorio *territorios[5];

    territorios[0] = new Territorio("Mexicano", 64350);

    territorios[1] = new Pais("Mexico", 60460, "Español", "Peso");
    territorios[2] = new Pais("Estados Unidos", 120560, "Ingles", "Dolar");

    territorios[3] = new Estado("Sinaloa", 23450, 56807);
    territorios[4] = new Estado("Colima", 12364, 67890);

    for (int i = 0; i < 5; i++){
    cout << territorios[i]->obtenerDatos() << endl;
    }

    return 0;
}