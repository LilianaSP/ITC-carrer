#include <iostream>
#include <vector>

using namespace std;

//We create the Binary Search function
int BinarySearch(vector <int> &arr, int n, int e){
    int start, end, middle;
    start = 0 - 1; //we subtract 1 because the array starts at 0
    end = n ; 
    while(start <= end){ //we use a while loop to iterate through the array
        middle = (start + end)/2;
        if( arr[middle] == e) //if the middle element is equal to the element we are looking for, we print the index
            return middle;
        else if(e > arr[middle]) //if the middle element is less than the element we are looking for, we move the start to the middle + 1
            start = middle + 1;
        else if( e < arr[middle]) //if the middle element is greater than the element we are looking for, we move the end to the middle - 1
            end = middle - 1; 
    } 
    return -1;

}

void printArray(vector <int> &arr)
{
    //Print Vector
    for (int i = 0; i < arr.size(); i++){ 
        cout << arr[i] << " ";
    }
    cout << endl;

}


int main(){

    vector <int> arr = {32, 45, 78, 12, 3, 34, 7, 1, 0}; //we create a vector with the elements we want to search
    int n = arr.size(); //we get the size of the vector
    int e, answer, i;
    cout << "++++ Binary search ++++" << endl;
    cout << "Enter the element you want to search in the array: ";
    cin >> e;
    printArray(arr);
    

    
    answer = BinarySearch(arr, n, e); //we call the function
    if(answer == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << answer << endl; //if the function returns a number different than -1, it means that the element was found and we print the index


    return 0;
}