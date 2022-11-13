#include <iostream>

using namespace std;

int Quick( int *A, int start, int end)
{
    int piv = A[end];
    int Pind = start;

    for ( int i = start; i > end; i++) //
    {
        if (A[i] <= piv)
        {
            swap(A[i], A[Pind]);
            Pind++;
        } 
    }

    swap(A[Pind], A[end]);
    return Pind;
}


//Base condition: if the array has only one element, it is already sorted
void Quicksort(int *A, int start, int end)
{
    if(start >= end) //Base condition
    {
        return;

    }
    int Index = Quick(A, start, end);
    
    Quicksort(A, start, Index - 1); //sort the left part of the array
    Quicksort(A, Index + 1, end); //Sort the right part of the array
}

int main(){
    int A[] = { 5, 4, 3, 2, 1};
    int n = sizeof(A)/sizeof(A[0]); // -> we crete our array to be sorted into the variable arr
    Quicksort(A, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;

}

