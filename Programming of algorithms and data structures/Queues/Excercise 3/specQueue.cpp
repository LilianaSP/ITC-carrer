#include <iostream>
using namespace std;

struct Node{
    //We create a node with a value and a pointer to the next node
    int data;
};

class Deque{
    private:
        Node *D;
        int N;
        int front, rear;
    public:
        Deque(int size){
            N = size;
            D = new Node[size];
            front = rear = -1;
        }
        ~Deque(){
            delete[] D;
        }
        //We create the functions that will be used
        //Push front function is to add elements at the front of the queue
        void Push_front(int);

        //Push back function is to add elements at the back of the queue
        void Push_back(int);

        //Pop front function is to remove elements from the front of the queue
        Node *Pop_front();

        //Pop back function is to remove elements from the back of the queue
        Node *Pop_back();
        
        //Display function is to display the elements of the queue
        void Display();
};

void Deque::Push_back(int value){
    if ( (front==0 && rear == N-1) || (front == rear+1) ){
        cout << "Deque is full." << endl;
        return;
    }
    if (front == -1){ //First element
        front = 0;
    }
    rear++;
    D[rear].data = value;
}

void Deque::Push_front(int value){
    if ( (front==0 && rear == N-1) || (front == rear+1) ){
        cout << "Deque is full." << endl;
        return;
    }
    if (front < 1){
        front = N-1;
    } else {
        front--;
    }
    D[front].data = value;
}

Node *Deque::Pop_back(){
    if(front == -1){
        cout << "Deque is empty." << endl;
        return NULL;
    }
    Node *Aux = &D[rear];
    if(front == rear){
        front = rear = -1;
    } else if (rear == 0){
        rear = N-1;
    } else {
        rear--;
    }
    return Aux;
}

Node *Deque::Pop_front(){
    if(front == -1){
        cout << "Deque is empty." << endl;
        return NULL;
    }
    Node *Aux = &D[front]; //only one element
    if(front == rear){
        front = rear = -1;
    } else if (front == N-1){ //front is at the end
        front = 0;
    } else { //0 <= front < rear    
        front++;
    }
    return Aux;
}
void Deque::Display(){
    if(front == -1){
        cout << "Deque is empty." << endl;
        return;
    }
    cout << "Elements: ";

    int end =(front>rear)? (N-1):rear;
    for (int i = front; i <= end; i++){
        cout << D[i].data << " ";
    }
    int ini = (front>rear)? 0:front;
    for(int i = ini; i <= rear; i++){
        cout << D[i].data << " "; 
    }
    cout << endl; 
}

int main(){
    cout << endl;
    Deque DQ(4);

    DQ.Push_back(8);
    DQ.Push_back(5);
    DQ.Push_back(7);
    DQ.Push_back(10);
    DQ.Display();

    DQ.Push_back(11);

    DQ.Pop_back();
    DQ.Pop_front();
    DQ.Display();

    DQ.Push_front(55);
    DQ.Push_back(45);
    DQ.Display();
    cout << endl;
    return 0;
}