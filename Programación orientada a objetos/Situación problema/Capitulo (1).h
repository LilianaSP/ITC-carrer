#ifndef CAPITULOS_H
#define CAPITULOS_H
#include <iostream>

class Capitulo{
    public:
        Capitulo();
        Capitulo(int, std::string, int);

        //getters
        std::string getNombreCapitulo() const;
        int getTemporada() const;
        int getDuracion() const;

        //setters
        void setNombreCapitulo(std::string);
        void setTemporada(int);
        void setDuracion(int);
        void imprime();

    private:
        std::string nombreCapitulo;
        int temporada;
        int duracion;

};
#endif