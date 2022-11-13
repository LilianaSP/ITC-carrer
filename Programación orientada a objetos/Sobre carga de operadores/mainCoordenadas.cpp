#include <iostream>
#include "CoordRect.h"
#include "CoordPolar.h"
using namespace std;

int main(){
    CoordRect c1(2,3);
    CoordRect c2(4,7);
    CoordPolar c4(6,8);
    CoordRect suma=c1+c2;
    CoordRect sumapolar_rectangular = c2+c4;
    cout << suma << endl;
    cout << sumapolar_rectangular << endl;
    return 0;
}