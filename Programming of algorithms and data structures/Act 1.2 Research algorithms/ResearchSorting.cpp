#include <iostream>
#include <vector>

using namespace std;
//We create the functions that we are going to use to sort arrays

//Fisrt function: Exchange sort
 //complexity of the algorithm is O(n^2)
void swap (int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//complexity of the algorithm is O(n^2)
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



//complexity of the algorithm is O(n log n)
void merge(vector<int>&array,int start, int middle, int end){
    int i,j,k;
    int leftElements = middle - start + 1;
    int rightElements = end - middle;

    vector<int>left_vec(leftElements);
    vector<int>right_vec(rightElements);

    for(int i = 0; i < leftElements; i++){
        left_vec[i] = array[start+i];
    }
    for(int j = 0; j < rightElements; j++){
        right_vec[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while(i < leftElements && j < rightElements){
        if(left_vec[i] <= right_vec[j]){
            array[k] = left_vec[i];
            i++;
        }else{
            array[k] = right_vec[j];
            j++;
        }
        k++;
    }

    while(j < rightElements){
        array[k] = right_vec[j];
        j++;
        k++;
    }

    while(i < leftElements){
        array[k] = left_vec[i];
        i++;
        k++;
    }

}

void mergeSort(vector<int>&array,int start, int end){
    if(start < end){
        int middle = start + (end - start)/2;
        mergeSort(array,start,middle);
        mergeSort(array,middle+1,end);
        merge(array,start,middle,end);
    }
}

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

int BinarySearch(vector <int> &arr, int n, int pos)
{
    //Binary search
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == pos) //if the element is found, we return the index
        {
            return mid; //return the index
        }
        else if (arr[mid] < pos) //if the element is greater than the middle element, we search in the right part of the array
        {
            low = mid + 1;
        }
        else //if the element is less than the middle element, we search in the left part of the array
        {
            high = mid - 1;
        }
    }
    return -1; //if the element is not found we return -1
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
    
    vector <int> vecE = {78,3,54,23,12,9,21}; // -> we crete our array to be sorted into the variable arr
    vector <int> vec2E = {22, 4, 12, 67, 43, 78};
    vector <int> vec3E = {12, 33, 2, 77, 3, 10, 5};
    vector <int> vec4E = {56, 71, 2, 5, 66, 4, 21, 8};

    exchangeSortVector(vecE); // call the function to sort the array that we created above
    exchangeSortVector(vec2E);
    exchangeSortVector(vec3E);
    exchangeSortVector(vec4E);

    cout << endl;
    cout << "++++Exchange sort vector++++" << endl;
    cout << " ++++ Complexity of the algorithm is O(n^2) ++++" << endl;
    cout << "Sorted arrays: \n";
    printArray(vecE);
    printArray(vec2E);
    printArray(vec3E);
    printArray(vec4E);


    cout << endl;

    cout << "++++Bubble sort vector++++" << endl;
    cout << " ++++ Complexity of the algorithm is O(n^2) ++++" << endl;
    cout << "Sorted arrays:" << endl;
    vector <int> vecB = {23, 4, 78, 5, 1, 2, 12};
    vector <int> vec2B = {12, 33, 2, 77, 3, 10, 5};
    vector <int> vec3B = {56, 71, 2, 5, 66, 4, 21, 8};
    vector <int> vec4B = {9, 4, 21, 3, 56, 108, 106, 0};

    BubbleSortVector(vecB);
    BubbleSortVector(vec2B);
    BubbleSortVector(vec3B);
    BubbleSortVector(vec4B);

    printArray(vecB);
    printArray(vec2B);
    printArray(vec3B);
    printArray(vec4B);

    cout << endl;

    cout << "++++ Merge Sort ++++" << endl;
    cout << " ++++ Complexity of the algorithm is O(n log n) ++++" << endl;
	cout << "Sorted arrays: " << endl;
    vector<int> array = {12,2,61,222,9,34,1};
	vector<int> array2 = {3,43,121,0,68,2,9,14,1};
	vector<int> array3 = {1,34,9,21,32,0,12,4,23};
	vector<int> array4 = {1,22,32,5,62,74,8,92};
    
    mergeSort(array,0,array.size()-1);
	mergeSort(array2,0,array2.size()-1);
	mergeSort(array3,0,array3.size()-1);
	mergeSort(array4,0,array4.size()-1);

    printArray(array);
	printArray(array2);
	printArray(array3);
	printArray(array4);
    cout << endl;

     //Sequential search
    cout << "++++Sequential search++++" << endl;
    cout << " ++++ Complexity of the algorithm is O(n) ++++" << endl;

    vector <int> arr = {32, 45, 78, 12, 3, 34, 7, 1, 0}; //we create a vector with the elements we want to search
    vector <int> arr2 = {21, 45, 56, 2, 56, 12,7, 1, 32};
    vector <int> arr3 = {31, 1, 7, 90, 122, 44, 34, 8};
    vector <int> arr4 = {34, 6, 12, 31, 8, 10, 15, 22, 5};
    int n = arr.size(); //we get the size of the vector
    int p = arr2.size(); //we get the size of the vector
    int w = arr3.size();
    int z = arr4.size();


    int e, answer, i, answer2, answer3, answer4, answer5;
    e = 32;
    cout << "Element you want to search: " << e << endl;
    cout << endl;
    answer = SequentialSearch(arr, n, e); //we call the function
    answer2 = SequentialSearch(arr2, p,  e);
    answer3 = SequentialSearch(arr3, w, e);
    answer4 = SequentialSearch(arr4, z, e);
    

    printArray(arr);
    if(answer == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answer << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    cout << endl;

    printArray(arr2);
    if(answer2 == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answer2 << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    cout << endl;

    printArray(arr3);
    if(answer3 == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answer3 << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    cout << endl;

    printArray(arr4);
    if(answer4 == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answer4 << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    
    cout << endl;
    cout << "++++Binary search++++" << endl;
    cout << " ++++ Complexity of the algorithm is O(log n) ++++" << endl;
    cout << "Sorted arrays: " << endl;
    
    int answerBinary = BinarySearch(array, array.size(), e);
    int answerBinary2 = BinarySearch(array2, array2.size(), e);
    int answerBinary3 = BinarySearch(array3, array3.size(), e);
    int answerBinary4 = BinarySearch(array4, array4.size(), e);

    cout << "Element that you want to search: " << e << endl;
   
    
    if(answerBinary == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answerBinary << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    printArray(array);
    cout << endl;

    if(answerBinary2 == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answerBinary2 << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    printArray(array2);
    cout << endl;

    if(answerBinary3 == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answerBinary3 << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    printArray(array3);
    cout << endl;

    if(answerBinary4 == -1) //if the function return -1, it means that the element was not found
        cout << "Element not found in the array" << endl;
    else
        cout << "Element found at index: " << answerBinary4 << endl; //if the function returns a number different than -1, it means that the element was found and we print the index
    printArray(array4);
    cout << endl;

    return 0;


}

