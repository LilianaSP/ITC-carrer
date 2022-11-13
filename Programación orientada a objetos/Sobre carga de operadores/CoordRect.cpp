#include "CoordRect.h"
#include "CoordRect.h"
CoordRect::CoordRect(){
    x=0;
    y=0;
}
CoordRect::CoordRect(double xx, double yy){
    x=xx;
    y=yy;
}
double CoordRect::getX() const{
    return x;
}
double CoordRect::getY() const{
    return y;
}
void CoordRect::setX(double xx){
    x=xx;
}
void CoordRect::setY(double yy){
    y=yy;
}

CoordRect CoordRect::operator +(const CoordRect& otra){
    return CoordRect(this->x + otra.x, this->y +otra.y);

}

ostream& operator <<(ostream& salida, const CoordRect& aimprimir){
    salida << "(" << aimprimir.x << "," << aimprimir.y << ")";
    return salida;

}

CoordRect CoordRect::operator +(const CoordPolar& cp){
    double xx = cp.getR()*sin(cp.getAngulo()*M_PI/180);
    double yy = cp.getR()*cos(cp.getAngulo()*M_PI/180);
    CoordRect resultado (x +xx, y + yy);
    return resultado;
}






