
#include <iostream>

#include <stdio.h>


using namespace std;

//Compute Fibonacci 

int fibo(int i){
    //cout << "Entering to compute f" << i << endl; //to see how many times the function is called
    //Base step
    if (i <= 2)
        return 1;
    
    //Induction
    return fibo(i - 1)+ fibo( i -2);

}

int fact(int n){
    //Fibonacci factorial solution
    if(n <= 0) return 1; //Base
    return n * fact(n - 1);// Induction
}

int main(){
    //We use the function fibo that we created above 
    cout << fibo(8) << endl;
    cout << fact(3) << endl;

    return 0;
}