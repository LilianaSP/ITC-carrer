#include <iostream>
#include <vector>
using namespace std;

//we create the function that we are going to use to sort the array
//Function: Insertion sort vector

void insertionSortVector(vector<int> &vec) //we create the function

{
    int i, j, temp; //We create the variables that we are going to use
    for (i = 1; i < vec.size(); i++)// we create the for loop
    {
        j = i; //we assign thr value of i to j
        while (j > 0 && vec[j] < vec[j-1]) //
        {
            temp = vec[j];
            vec[j] = vec[j-1]; //
            vec[j-1] = temp;
            j--; // we decrement j

        }
    }
}
 //we create the function that we are going to use to print the array
void print(vector<int> vec)
{
    for( int x : vec) 
        cout << x << " ";
    cout << '\n';
}


int main(){

    cout << "+++++Insertion sort vector++++ " << endl;
    cout << "Sorted arrays: " << endl;
    //We create the four test cases of our function
    vector <int> vec = {4, 12, 43, 56, 23}; //we create the vector
    vector <int> vec2 = {23, 5, 43, 22, 78, 9};
    vector <int> vec3 = {11, 3, 66, 43, 81, 1 ,6};
    vector <int> vec4 = {34, 61, 2, 6, 10, 0, 4};
    
    insertionSortVector(vec);
    insertionSortVector(vec2);
    insertionSortVector(vec3);
    insertionSortVector(vec4);

    print(vec);
    print(vec2);
    print(vec3);
    print(vec4);
    return 0;
}