#include <vector>
#include "Circulo.h"
#include "Rectangulo.h"
#include <iostream>

using namespace std;

int main(){
    
    //Figura f1(2,2);
    //Figura* f;
    //cout<<f1.dibuja()<<endl;
    //cout<<"Posicion: ("<<f1.getX() <<", "<<f1.getY()<<")"<<endl;

    //Circulo c1(3,4,6);
    
    //f = &c1;
    //cout<<f->dibuja()<<endl;
    //Figura* arr[5];

    
    //arr[0] = new Circulo(1,3,5);
    //arr[1] = new Rectangulo(1,1,2,3);
    //arr[2] = new Circulo(1,3,5);
    //arr[3] = new Rectangulo(1,1,2,30);
    //arr[4] = new Figura(1,2);

    vector<Figura*> figuras;
    figuras.push_back( new Circulo(1,3,5));
    figuras.push_back  (new Rectangulo(1,1,2,3));
    figuras.push_back (new Circulo(1,3,5));
    figuras.push_back (new Rectangulo(1,1,2,30));
    figuras.push_back (new Figura(1,2));
    


    for(int i = 0; i < 5; i++){
        //cout<< arr[i]->dibuja()<<endl;
        cout << "El árae es:  "<<figuras[i]->area() <<endl;
        if(Circulo* ptrCirc=dynamic_cast<Circulo*>(figuras[i])){
            cout <<"Circunferencia: "<<ptrCirc -> circunferencia()<< endl;
        }
    }
    cout<< "RECORRIDO CON FOR EACH" <<endl;
    for(auto &fig: figuras){
        cout << fig->dibuja()<<endl;

    }


    
    /*
    cout<<f.dibuja()<<endl;
    cout<<"Posicion: ("<<c1.getX() <<", "<<c1.getY()<<")"<< " con Radio: "<<c1.getRadio()<<endl;
    cout<<"Area: "<<c1.area()<<endl;

    Rectangulo r1(5,7,3,4);
    cout<<r1.dibuja()<<endl;
    cout<<"Posicion: ("<<r1.getX() <<", "<<r1.getY()<<")"<< " con un Largo de: " <<r1.getLargo() <<" y un Ancho de: "<<r1.getAncho()<<endl;
    cout<<"Area: "<<r1.area()<<endl;*/



    return 0;
}
