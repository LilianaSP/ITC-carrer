//Liliana Solórzano Pérez A01641392
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <vector>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//--------------Complexity of empty() is O(1)----------------
//-----------------PRIORITY QUEUE FUNCTIONS TIME COMPLEXITY-----------------
//-----------------Complexity of push() and pop() is O(log(n))-----------------
//-------Comlexity of pop() is O(1) if we are only interested in the top element-------
//-----------------Complexity of top() is O(1)-----------------
//-----------------Complexity of empty() is O(1)-----------------
//-----------------Complexity of size() is O(1)-----------------

//We create the node structure
struct Node{
    int value;
    int priority;
};

//We create the class HeapTree
class HeapTree{
    private:
        Node *PQ; //We create a pointer to a node in order to create the heap
        int n, Numer_Nodes; //We create the variables n and Numer_Nodes
    public:
        HeapTree(int size){
            n = size; //We assign the size to n
            PQ = new Node[n]; //We create the heap
            Numer_Nodes = -1; //We assign -1 to Numer_Nodes
        }
        ~HeapTree(){
            delete [] PQ; //We delete the heap
        }

        void push(int, int); //We create the push function
        Node *pop(); //We create the pop function
        int top(); //We create the top function
        void orderMaxHeap(int); //We create the orderMaxHeap function
        void MaxHeap(); //We create the MaxHeap function

        void Display(int); //We create the Display function
        void Display(); //We create the Display function
        bool empty(); //We create the empty function
        int size(); //We create the size function
};

//We create a function to see if our heap is empty
bool HeapTree::empty(){
    return Numer_Nodes == -1; //We return true if the heap is empty
}

//We create a function to see the size of our heap
int HeapTree::size(){
    return Numer_Nodes + 1; //We return the size of the heap
}

//We create the push function
void HeapTree::push(int value, int priority){
    if(Numer_Nodes == n-1){ //We check if the heap is full
        cout << "Heap Tree is full" << endl; //We print that the heap is full
        return; //We return
    }
    //We increase the size
    Numer_Nodes++;

    //We insert the element
    PQ[Numer_Nodes].value = value;
    PQ[Numer_Nodes].priority = priority;

    //We order the heap
    orderMaxHeap(Numer_Nodes);
}

//We create the pop function that uses the top function
Node *HeapTree::pop(){
    if(empty()){ //We check if the heap is empty
        cout << "Heap Tree is empty" << endl; //We print that the heap is empty
        return NULL; //We return NULL
    }
    //We create a node to store the top element
    Node *temp = new Node;
    temp->value = PQ[0].value;
    temp->priority = PQ[0].priority;

    //We replace the top element with the last element
    PQ[0].value = PQ[Numer_Nodes].value;
    PQ[0].priority = PQ[Numer_Nodes].priority;

    //We decrease the size
    Numer_Nodes--;

    //We order the heap
    MaxHeap();

    //We return the top element
    return temp;
}

//We create the top function
int HeapTree::top(){
    if(empty()){ //We check if the heap is empty
        cout << "Heap Tree is empty" << endl; //We print that the heap is empty
        return -1; //We return -1
    }
    //We create a for loop to print the top element of highest priority
    int highest_Priority = 0;
    int index_Highest_Priority = -1;

    for(int i = 0; i <= Numer_Nodes; i++){
        if(PQ[i].priority > highest_Priority){
            highest_Priority = PQ[i].priority;
            index_Highest_Priority = i;
        }
        else if(PQ[i].priority == highest_Priority && PQ[i].value < PQ[index_Highest_Priority].value){
            highest_Priority = PQ[i].priority;
            index_Highest_Priority = i;
        }
            
        }
    //We return the top element
    return index_Highest_Priority;

    }

void HeapTree::orderMaxHeap(int index){
    int left = 2*index + 1; //We create the left child
    int right = 2*index + 2; //We create the right child
    int largest = index; //We create the largest variable

    //We check if the left child is larger than the parent
    if(left <= Numer_Nodes && PQ[left].priority > PQ[largest].priority){
        largest = left;
    }
    else if(left <= Numer_Nodes && PQ[left].priority == PQ[largest].priority && PQ[left].value < PQ[largest].value){
        largest = left;
    }

    //We check if the right child is larger than the parent
    if(right <= Numer_Nodes && PQ[right].priority > PQ[largest].priority){
        largest = right;
    }
    else if(right <= Numer_Nodes && PQ[right].priority == PQ[largest].priority && PQ[right].value < PQ[largest].value){
        largest = right;
    }

    //We check if the largest is not the parent
    if(largest != index){
        //We swap the parent with the largest
        Node temp = PQ[index];
        PQ[index] = PQ[largest];
        PQ[largest] = temp;

        //We order the heap
        orderMaxHeap(largest);
    }

}


void HeapTree::MaxHeap(){
    //We create a for loop to order the heap
    for(int i = Numer_Nodes/2; i >= 0; i--){
        orderMaxHeap(i);
    }
}

void HeapTree::Display(int start_index){
    cout << PQ[start_index].value << endl; //We print the value of the node
}

void HeapTree::Display(){
    //We create a for loop to print the heap

    for(int i = 0; i <= Numer_Nodes; i++){
        cout << PQ[i].value << " ";
    }
    cout << endl;
}

int main (){
    //We create a heap with a size of 10
    HeapTree heapTree1(10);
    int num;
    srand(time(NULL));

    vector<int> vec = {55, 13, 22, 15, 18, 19, 37, 41, 16, 32}; // vector<int> v = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    cout << endl;
    cout << "++++ Inserting elements ++++" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        num = 1 + rand() % (11 - 1); // 11 - 1 
        heapTree1.push(vec[i], num);
        cout << "Push: " << vec[i] << " Priority: " << num << endl;
    }

    cout << endl;

    cout << "++++ Test cases ++++" << endl;
    heapTree1.Display();

    cout << "Max Heap" << endl;
    heapTree1.MaxHeap();
    cout << "Elements: "; 
    heapTree1.Display();

    int index = heapTree1.top();
    cout << "Top element: ";
    heapTree1.Display(index);
    cout << "Size of the heap tree: " << heapTree1.size() << endl;

    cout << endl;

    cout << "++++ Pop elements case 1++++" << endl;
    heapTree1.pop();
    cout << "Elements: ";
    heapTree1.Display();

    index = heapTree1.top();
    cout << "Top element: ";
    heapTree1.Display(index);
    cout << "Size of the heap tree: " << heapTree1.size() << endl;

    cout << endl;

    cout << "++++ Pop elements case 2 ++++" << endl;
    heapTree1.pop();
    cout << "Elements: ";
    heapTree1.Display();

    index = heapTree1.top();
    cout << "Top element: ";
    heapTree1.Display(index);
    cout << "Size of the heap tree: " << heapTree1.size() << endl;

    cout << endl;

    cout << "++++ Pop elements case 3 ++++" << endl;
    heapTree1.pop();
    cout << "Elements: ";
    heapTree1.Display();

    index = heapTree1.top();
    cout << "Top element: ";
    heapTree1.Display(index);
    cout << "Size of the heap tree: " << heapTree1.size() << endl;

    cout << endl;

    cout << "++++ Pop elements case 4 ++++" << endl;
    heapTree1.pop();
    cout << "Elements: ";
    heapTree1.Display();

    index = heapTree1.top();
    cout << "Top element: ";
    heapTree1.Display(index);
    cout << "Size of the heap tree: " << heapTree1.size() << endl;

    cout << endl;
    cout << " ++++ End of program ++++" << endl;


    




    return 0;
}



