#include <iostream>
#include <vector>
using namespace std;

void BubbleSortVector(vector <int> &vec)
{
    //Bubble sort vector
    int i, j;
    bool swapp = true; //swapp is a boolean variable that we use to check if the
    //array is sorted or not
    while (swapp){ //while swapp is true
        swapp = false;
        for (i = 0; i < vec.size() - 1; i++){ // - 1 because we are comparing the next element
            if (vec[i] > vec[ i + 1]){ // if the current element is greater than the next element
                swap(vec[i], vec[i +1]); // we swap the elements if the condition is true
                swapp = true; // we set swapp to true
            }
        }
    }
}

void printVector(vector <int> &vec)
{
    //Print Vector
    for (int i = 0; i < vec.size(); i++){ 
        cout << vec[i] << " ";
    }
    cout << endl;

}

int main(){
    //Bubble sort vector
    cout << "++++Bubble sort vector++++" << endl;
    cout << "Sorted vector:" << endl;
    vector <int> vec = {23, 4, 78, 5, 1, 2, 12};
    vector <int> vec2 = {12, 33, 2, 77, 3, 10, 5};
    vector <int> vec3 = {56, 71, 2, 5, 66, 4, 21, 8};
    vector <int> vec4 = {9, 4, 21, 3, 56, 108, 106, 0};



    BubbleSortVector(vec);
    BubbleSortVector(vec2);
    BubbleSortVector(vec3);
    BubbleSortVector(vec4);


    printVector(vec);
    printVector(vec2);
    printVector(vec3);
    printVector(vec4);

    return 0;
}