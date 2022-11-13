#include <iostream>
#include <vector>
using namespace std;

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

void printArray(vector<int>array){
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
	cout << "++++ Merge Sort ++++" << endl;
	cout << "Sorted arrays: " << endl;
    vector<int> array = {12,0,6,2,9,34,1};
	vector<int> array2 = {23,43,12,0,6,2,9,34,1};
	vector<int> array3 = {1,34,9,2,6,0,12,43,23};
	vector<int> array4 = {1,22,31,5,62,74,8,92};
    
    mergeSort(array,0,array.size()-1);
	mergeSort(array2,0,array2.size()-1);
	mergeSort(array3,0,array3.size()-1);
	mergeSort(array4,0,array4.size()-1);

    printArray(array);
	printArray(array2);
	printArray(array3);
	printArray(array4);
   
    return 0;
}