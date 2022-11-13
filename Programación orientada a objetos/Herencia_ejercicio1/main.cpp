#include <iostream>
#include "circulo.h"
#include "rectangulo.h"

using namespace std;


int main(){
    Figura f1(2,2);
    cout<<f1.dibuja()<<endl;
    cout<<"Posición: " <<f1.getX() << "," << f1.getY()<<endl;

    Circulo c1(3,4,6);
    cout<< c1.dibuja()<<endl;
    cout<<"Posición: "<<c1.getX() <<"," <<c1.getY()<<" Radio: "<<c1.getRadio()<<endl;
    cout<< "Area: "<< c1.area()<<endl;


    Rectangulo r1(4,4,4,4);
    cout<<r1.dibuja()<<endl;
    cout << "Posición: "<<r1.getX()<< ","<<r1.getY() << " Ancho: " << r1.getAncho()<< " Largo: " << r1.getLargo()<<endl;
    //cout<<"Posición: "<<r1.getX() <<","<<r1.getY()<<" Ancho: "<<r1.getAncho()<< " Largo: " << r1.getLargo()<<endl;
    cout << "Area: "<<r1.area_r()<<endl;
    return 0;

   


}