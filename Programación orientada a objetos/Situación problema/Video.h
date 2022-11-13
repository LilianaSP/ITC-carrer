//Clase base
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>


class Video{

    public:
        Video();
        Video(std::string, std::string, std::string, double, int);
        
        //getters
        
        std::string getGenero() const;
        std::string getTitulo() const;
        std::string getClasificacion() const;
        int getPersonas() const;
        double getRating() const;

        
        //setters
        
        void getGenero(std::string);
        void setTitulo(std::string);
        void setClasificacion(std::string);
        void setPersonas(int);
        void setRating(double);
        virtual void imprime(); // funcionn polimorfica
        void operator + (const double); //sobrecarga de operador + 

    private:
        std::string genero;
        std::string titulo;
        std::string clasificacion;
        int personas;
        double rating; 
};

#endif