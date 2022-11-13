#include <iostream>

using namespace std;

struct Node{
    int num;
};

class Queue{
    private:
        int N, Front, Rear;
        Node *Q; //The pointer st stores the created array of nodes in dynamic memory

    public:
        Queue(int size){
            Front = -1; //The queue is empty - in charge of keeping track of the top of the queue
            Rear = -1;
            N = size; //The size of the queue
            Q = new struct Node[N]; //We create the queue of nodesof size N
        }
        ~Queue(){
            cout << "Destructor: Earse the queue" << endl;
            delete[] Q;
        }

        void Enqueue(int);
        struct Node *Dequeue();
        void Display();
        bool isEmpty();
};

void Queue::Enqueue(int n){
    if (Front == 0 && Rear == N-1)
        cout << "Queue overflow" << endl;
    else{
        if (Front == -1) //If the queue is empty
            Front = 0; //We move the front to the first position
        Rear++;
        Q[Rear].num = n; //We store the number in the top of the queue to acces it we use Q[Rear].num
    }
}

Node *Queue::Dequeue(){
    if(Front == -1){ //If the queue is empty
        cout << "Queue underflow" << endl;
        return NULL;
    }

    Node *Aux = &Q[Front]; //We store the node that is going to be removed
    if(Front >= Rear){ //If the queue has only one element
        Front = -1; //We reset the queue
        Rear = -1; 
    }
    else{
        Front++; //we move the front to the next position, increasing the queue +1
    }

    return Aux;
}

bool Queue::isEmpty(){
    if (Front == -1) //If the queue is empty, the front is -1, it returns a null value
        return true;
    return false; //Otherwise, it returns a true value
}

void Queue::Display(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << endl << "Front -> ";
        for(int i = Front; i <= Rear; i++){
            cout << Q[i].num << " ";
        }
        cout << "<- Rear" << endl;
    }
//---------------------Complexity of the display O(n)---------------------
}

//----------------Complexity of the queue O(1)----------------

int main(){
    Queue C(3);
    int x;
    for (int i = 0; i < 4; i++){
        cout << "Enter a value: ";
        cin >> x;
        C.Enqueue(x);
    }
    C.Display();

    while (!C.isEmpty()){
        cout << C.Dequeue()->num << " " << endl; //We print the value of the node that was removed
    }

    return 0;
}