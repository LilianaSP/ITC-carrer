#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Capitulo.h"
#include <vector>

class Serie:public Video{
    public:
        Serie();
        Serie(std::string, std::string, std::string, double, int, int,int);


        //getters de series
        int getTemporada() const;
        int getNumCapitulo() const;
    
        

        //setters
        void setTemporada(int);
        void setNumCapitulo(int);
        void agregaCapitulo(Capitulo& ); // push back del vector
        void imprime() override;  // funcion polimorfica

    private:
        
        //atributos únicos de serie
        int temporada;
        int numCapitulo;
        //vector para guardar todos los capitulos
        std::vector<Capitulo> capitulo;

};

#endif
