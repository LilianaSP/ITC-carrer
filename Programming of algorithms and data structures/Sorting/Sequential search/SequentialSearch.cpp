#include <iostream>
#include <vector>

using namespace std;

int SequentialSearch(vector <int> &arr, int n, int pos)
{
    //Sequential search
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == pos) //if the element is found, we return the index
        {
            return i; //return the index
        }
    }
    return -1; //if the element is not found we return -1
    
}

void printArray(vector <int> &arr)
{
    for( int i = 0; i < arr.size(); i++) //we iterate trough the array
    {
        cout << arr[i] << " "; //we print the elements
    }
    cout << endl;
}


int main(){
    //Sequential search
    cout << "++++Sequential search++++" << endl;
    vector <int> arr = {32, 45, 78, 12, 3, 34, 7, 1, 0}; //we create a vector with the elements we want to search
    int n = arr.size(); //we get the size of the vector
    int e, answer, i;
    cout << "Enter the element you want to search in the array: ";
    cin >> e;
    answer = SequentialSearch(arr, n, e); //we call the function
    printArray(arr);
    if(answer == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answer << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    
    return 0;
}