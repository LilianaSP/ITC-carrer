#ifndef FIGURA_H
#define FIGURA_H
#include <string>

class Figura{
    public:
        Figura();
        Figura(int,int);
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        virtual std::string dibuja();
        virtual double area() = 0;

    private:
        int x,y;
};

#endif