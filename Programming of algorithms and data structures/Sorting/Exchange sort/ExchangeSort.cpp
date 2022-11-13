#include <iostream>
#include <vector>
using namespace std;


//We create the functions that we are going to use to sort arrays

//Fisrt function: Exchange sort

void swap (int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void exchangeSortVector(vector <int> &vec)
{
    int i, j, min_num;

    //we create the for loop 
    //it change the number one by one moving the minimum element 
    for (i = 0; i < vec.size()-1; i++)
    
    {
        //Finding the minimum element in the array
        min_num = i;
        for (j = i+1; j < vec.size(); j++)
        if (vec[j] < vec[min_num])
            min_num = j;

            //Swaping the found elements with the firts element
        
        if (min_num != i)
            swap(&vec[min_num], &vec[i]);
    }
}

//We create a functin to print the array
void printArray(vector <int> &vec)
{
    int i;
    for(i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}


int main(){

    //We create the main program with the array that we want to sort
    //We have to sort the array in decreasing order
    
    
    vector <int> vec = {78,3,54,23,12,9,21}; // -> we crete our array to be sorted into the variable arr
    vector <int> vec2 = {22, 4, 12, 67, 43, 78};
    vector <int> vec3 = {12, 33, 2, 77, 3, 10, 5};
    vector <int> vec4 = {56, 71, 2, 5, 66, 4, 21, 8};

    exchangeSortVector(vec); // call the function to sort the array that we created above
    exchangeSortVector(vec2);
    exchangeSortVector(vec3);
    exchangeSortVector(vec4);

    cout << "++++Exchange sort vector++++" << endl;
    cout << "Sorted array: \n";
    printArray(vec);
    printArray(vec2);
    printArray(vec3);
    printArray(vec4);
    return 0;
}




