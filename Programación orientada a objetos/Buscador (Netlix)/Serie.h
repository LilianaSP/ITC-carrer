#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Capitulo.h"
#include <vector>

class Serie:public Video{
    public:
        Serie();
        Serie(std::string, std::string, std::string, int, int, int);

        //getters de series
        int getTemporada() const;
        int getNumCapitulo() const;
        Capitulo getCapitulo (Capitulo&, int); //obtener un capítulo que se encuentra en una determinada posición del vector
        

        //setters
        void setTemporada(int);
        void setNumCapitulo(int);
        void agregaCapitulo(Capitulo& ); // push back del vector
        void imprime() override;

    private:
        
        //atributos únicos de serie
        int temporada;
        int numCapitulo;
        std::vector<Capitulo*> capitulo;

};

#endif
