//Clase base
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include "Serie.h"

class Video{

    public:
        Video();
        Video(std::string, std::string, std::string, int);
        
        //getters
        
        std::string getGenero() const;
        std::string getTitulo() const;
        std::string getClasificacion() const;
        int getRating() const;

        
        //setters
        
        void getGenero(std::string);
        void setTitulo(std::string);
        void setClasificacion(std::string);
        void setRating(int);
        virtual void imprime();

    private:
        std::string genero;
        std::string titulo;
        std::string clasificacion;
        int rating;
};

#endif