#include <iostream>
#include <vector>
using namespace std;

void pruebaExcepcion1(){
    // manejo de excpecion estandar
  try  {
    throw 2;
  }
  catch (int e){
    cout << "Se prueba el MANEJO ESTANDAR de EXCEPCIONES, ha ocurrido la excepcion " << e << '\n';
  }
    }

void pruebaExcepcion4(){
    int edad;
    cout << "Introduce tu edad: ";
    cin >> edad;
    try {
      if (edad >= 18) {
        cout << "Acceso permitido.";
      }
      else {
        throw (edad);
      }
    }
    catch (int numeroDelThrow) {
      cout << "Acceso denegado - debes tener 18 anios.\n";
      cout << "Edad: " << numeroDelThrow;
    }
}

void pruebaExceptionCiclada(){
    int x, y;
    cout << "ingresa es dividendo: ";
    cin >> x;
    cout << "ingresa el divisor: ";
    cin >> y;
    while(true){
        try{
            if(y==0){
                throw "Division por cero, no puedo realizarlo";
            }
            int z=x/y;
            cout << "El resultado de la division es: " << z << endl;
            break;
        }
        catch(const char* msg){
            cerr << msg << endl;
            cout << "Ingresa otro denominador: ";
            cin >> y;
        }
    }
}

int main(){
    //Hay métodos que generan excepeciones
    int index;
    vector<int> numeros;
    numeros.push_back(12);
    cout << "Posición que quieres revisar: ";
    cin >> index;
    cout << numeros.at(index) << endl;

    //Manejo de excepciones
    try {
        cout << numeros.at(index) << endl;
    }
    catch ( out_of_range &ex ) { 
        cerr << "Ocurrio una excepcion: " << ex.what() << endl; 
    }
    cout << "El programa continua" << endl;


}
