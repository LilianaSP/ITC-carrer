#include <iostream>

using namespace std;
int ite(int n){
    int sum = 0;
    for(int i = 0; i<=n; i++){
        sum += i;  
    }
    return sum;

}

int recur(int x){
    if (x < 0) return 0;
    return x + recur(x-1);

}

int directsum(int z){
    if (z <= 1) return 0;
        return (z*(z+1))/2;
}


int main(){
    cout << "\n++++ Iterative sum +++++" << endl;
    cout << "Iterative sum: "<< ite(5)<< endl;
    cout << "Iterative sum: "<< ite(15)<< endl;
    cout << "Iterative sum: "<< ite(4)<< endl;
    cout << "Iterative sum: "<< ite(8)<< endl;

    cout << "\n++++ Recursive sum ++++" << endl;
    cout << "Recursive sum: "<<recur(5)<< endl;
    cout << "Recursive sum: "<<recur(2)<< endl;
    cout << "Recursive sum: "<<recur(9)<< endl;
    cout << "Recursive sum: "<<recur(7)<< endl;

    cout << "\n++++ Direct sum ++++" << endl;
    cout << "Direct sum: "<<directsum(9)<< endl;
    cout << "Direct sum: "<<directsum(3)<< endl;
    cout << "Direct sum: "<<directsum(8)<< endl;
    cout << "Direct sum: "<<directsum(19)<< endl;

    return 0;
}