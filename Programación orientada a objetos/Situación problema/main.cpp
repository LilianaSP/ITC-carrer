#include "Biblioteca.h"
#include "Capitulo.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Video.h"
#include <iostream>
#include <vector>

//Victoria Ramírez Castro A01640824
//Liliana Solórzano Pérez A01641392

using namespace std;


int main(){
    // Se crea la biblioteca y se carga su base de datos
    Biblioteca biblioteca;
    biblioteca.cargarDatos();

    // Declaracion de las variables
    string bandera = "S",
           usuario = "",
           titulo = "",
           genero = "",
           clasificacion = "",
           tituloR = "";
    int op = 0,
        op2 = 0,
        tipo = 0;
    
    double rating = 0.0,
           cali = 0.0;

    // Desplegar menu ciclado, aqui va a ser toda la interaccion del programa con el usuario
    
    cout << "------Bienvenidos a NETFLIX-----" <<endl
            << "Este programa esta hecho por Victoria y Liliana" << endl
            << "Antes de iniciar, vamos a crear su cuenta"<<endl
            << "Ingrese su nombre de usuario"<<endl;
            cout<<">> ";
            getline(cin, usuario);
            cout<< "\nBienvenid@ "<<usuario<<", gracias por preferir nuestra aplicacion"<<endl;
    
    while(bandera != "N"){
        if (bandera == "S"){
            cout<<"\nSeleccione la opcion que prefiera" << endl
            << "1) Mostrar catalogo"<<endl
            << "2) Seleccionar pelicula"<<endl
            << "3) Seleccionar serie"<<endl
            << "4) Calificar video"<<endl          
            << "5) Salir"<<endl;
            cout<<">> ";
            cin >> op;
          
    
            system("clear");
           //Depende de lo que el usuario ingrese, va a entrar a algun case del switch case
          
            switch (op){
                case 1:
                    biblioteca.imprime();
                    cout<<"¿Quiere regresar al menu principal? (S/N)"<<endl;
                    cout<<">> ";
                    cin>>bandera;
                    system("clear");
                    break;
                case 2:
                    tipo = 1; // el tipo es para saber si lo que quieres buscar es pelicula o serie 
                    cout << "Buscar peliculas por: "<<endl
                         << "1) Titulo"<<endl
                         << "2) Genero"<<endl
                         << "3) Clasificacion"<<endl
                         << "4) Rating"<<endl;
                    cout<<">> ";
                    cin >> op2;
                    cin.ignore(); // sirve para que no se cicle el menu y lea toda la linea

                
                    switch (op2){
                        case 1:
                            cout<<"Pelicula que desea buscar: "<<endl;
                            cout<<">> ";
                            getline(cin, titulo);
                            biblioteca.consultarTitulo(titulo);
                            
                        break;
                        case 2:
                            cout<<"Genero que desea buscar: "<<endl;
                            cout<<">> ";
                            cin>>genero;
                            biblioteca.consultarGenero(genero, tipo); 
                        break;
                        case 3:
                            cout<<"Clasificacion que desea buscar: "<<endl;
                            cout<<">> ";
                            cin>>clasificacion;
                            biblioteca.consultarClasificacion(clasificacion, tipo); 
                        break;
                        case 4:
                            cout<<"Rating que desea buscar: "<<endl;
                            cout<<">> ";
                            cin>>rating;

                            while (true){
                              try{
                                if (rating < 1 || rating > 5){
                                  throw "El rating debe de estar entre 1 y 5 (puede tener decimales)";
                                  
                                }
                                biblioteca.consultarRating(rating, tipo); 
                                system("clear");

                                break;
                              }
                            catch (const char* msg){
                              system("clear");
                              cerr <<msg << endl;
                              cout << "Ingresa nuevamente un rating válido " << endl <<"<<";
                              cin >> rating;
                            }
                            }
                            
                        break;
                        
                        default:
                        break;
                    }
                    
                    cout<<"\n¿Quiere regresar al menu principal? (S/N)"<<endl;
                    cout<<">> ";
                    cin>>bandera;
                    system("clear");
                    break;
                case 3:
                    tipo = 2; // el tipo es para saber si lo que quieres buscar es pelicula o serie 
                    cout << "Buscar serie por: "<<endl
                         << "1) Titulo"<<endl
                         << "2) Genero"<<endl
                         << "3) Clasificacion"<<endl
                         << "4) Rating"<<endl;
        
                    cout<<">> ";
                    cin >> op2;
                    cin.ignore();

                    switch (op2){
                        case 1:
                            cout<<"Serie que desea buscar: "<<endl;
                            cout<<">> ";
                            getline(cin, titulo);
                            biblioteca.consultarTitulo(titulo);
                            
                        break;
                        case 2:
                            cout<<"Genero que desea buscar: "<<endl;
                            cout<<">> ";
                            cin>>genero;
                            biblioteca.consultarGenero(genero, tipo);
                        break;
                        case 3:
                            cout<<"Clasificacion que desea buscar: "<<endl;
                            cout<<">> ";
                            cin>>clasificacion;
                            biblioteca.consultarClasificacion(clasificacion, tipo);
                        break;
                      
                        case 4:
                            cout<<"Rating que desea buscar: "<<endl;
                            cout<<">> ";
                            cin>>rating;
                                // se hace un manejo de excepciones para asegurarnos de que el rating se desea buscar este entre 1 y 5
                                while (true){
                                  try{
                                    if (rating < 1|| rating > 5){
                                      throw "El rating debe de estar entre 1 y 5 (puede tener decimales)";
                                    } 
                                    biblioteca.consultarRating(rating, tipo);
                                    system ("clear");

                                    break;
                                  }
                                catch (const char* msg){
                                  system("clear");

                                  cerr << msg << endl;
                                  cout << "Ingresa nuevamente un rating válido"<<endl<<">>";
                                  cin >> rating;
                                }
                              
                          }
                          
                            
                          break;
                        
                          default:
                          break;
                    }
                    cout<<"¿Quiere regresar al menu principal? (S/N)"<<endl;
                    cout<<">> ";
                    cin>>bandera;
                    system("clear");
                    break;
              
                case 4:
                    cin.ignore();
                    cout << "Escriba el titulo del video a calificar"<<endl
                         << ">> ";
                    getline(cin, tituloR); 
                    
                    cout << "Ingrese la calificacion"<<endl
                         <<">> ";
                    cin >> cali;

                    //Volvemos a utilizar un manejo de excepciones para asegurarnos de que la calificacion que le de el usuario a algun video este entre 1 y 5
                    while(true){
                        try{
                            if(cali < 1 || cali>5){
                                throw "La calificacion tiene que estar entre 1 y 5";
                            }
                            biblioteca.calificar(tituloR, cali);
                            system("clear");

                            break;
                        }
                        catch(const char* msg){
                            system("clear");

                            cerr << msg << endl;
                            cout << "Ingrese la calificacion"<<endl
                                 <<">> ";
                            cin >> cali;
                        }
                    }

                    break;
                case 5:
                    //Se sale del programa
                    cout<<"-------Gracias por usar NETFLIX------"<<endl;
                    bandera = "N";
                    system("clear");
                    break;
    
                default:
                    break;
            
            }
        }    
        
    }
    return 0;
}