#include <iostream>
#include <vector>

using namespace std;


void swap(int *xp, int * yp) //We create the function that will help us to swap the elements of the vector
{
    int temp = *xp; //We cerate a variable temp to store the value of xp
    *xp = *yp; //We assign the value of yp tp xp
    *yp = temp; //We assign the value of temp to yp
}

//We create the functions of the sequential sort vector
void SequentialSortVector(vector <int> &vec)
{
    //Sequential sort vector
    int i, j, num_min;
    for ( i = 0; i < vec.size() - 1; i++)
    {
        //Finding the minimum element in the array
        num_min = i;
        for (j = i + 1; j < vec.size(); j++) //We create the for loop to find the minimum element
        if (vec[j] < vec[num_min]) //We compare the elements of the vector
            num_min = j; //we assign the value of j to num_min
        if (num_min != i) //we compare the values of num_min and i of the vector
            swap(vec[num_min], vec[i]); //We use the function swap to swap the elements
    }


}

void printVector(vector <int> &vec)
{
    //Print Vector
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " " ;
    }
    cout << endl;
        
}


int main(){

    int a;
    a = rand() % 100;

    //Sequential sort vector
    cout << "++++Sequential sort vector++++" << endl;
    cout << "Sorted vector:" << endl;

    vector <int> vec = {2 ,4 , 12, 43 , 7, 9, 0, 0};
    vector <int> vec2 = {34, 6, 1, 62, 3, 11, 8, 70};
    vector <int> vec3 = {33, 4, 112, 6, 7, 12, 143, 5, 3};
    vector <int> vec4 = {43, 78, 9, 22, 54, 567, 123,43, 96};

    SequentialSortVector(vec);
    SequentialSortVector(vec2);
    SequentialSortVector(vec3);
    SequentialSortVector(vec4);

    printVector(vec);
    printVector(vec2);
    printVector(vec3);
    printVector(vec4);

    return 0;
}