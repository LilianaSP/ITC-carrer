#include <iostream>

using namespace std;

struct Node{
    int num;
};

class Stack{
    private:
        int N, Top;
        Node *St; //The pointer st stores the created array of nodes in dynamic memory
    public:
        Stack(int size){
            Top = -1; //The stack is empty - in charge of keeping track of the top of the stack
            N = size; //The size of the stack
            St = new struct Node[N]; //We create the stack of nodesof size N
        }
    ~Stack(){
        cout << "Destructor: Erase the stack" << endl;
        delete[] St;
    }
    void Push(int);
    struct Node *Pop();
    int *Peek();
    bool isEmpty();
    
};

void Stack::Push(int Num){
    if(Top == N-1){ //Make sure if the stack is full
        cout << "Stack overflow" << endl;
    }
    else{
        Top++; //If the stack is not full, we increase the top of the stack
        St[Top].num = Num; //We store the number in the top of the stack to acces it we use St[Top].num
    }
}

struct Node *Stack::Pop(void){
    if(Top < 0){
        cout << "Stack underflow" << endl;
        return NULL;
    }
    Top --;
    return &St[Top+1]; //We return the node that was removed from the stack
};

bool Stack::isEmpty(){
    if (Top > 0) //If the stack is empty, the top is -1, it returns a null value
        return true;
    return false; //Otherwise, it returns a true value
}

int *Stack::Peek(){
    if(Top < 0){ //If the stack is empty, the top is -1, it returns a null value
        cout << "Stack underflow" << endl;
        return NULL; //We return the top of the stack
    }
    return &St[Top].num; //We return the top of the stack. To get the value of the Node we use St[Top].num
};
//Time complexity O(1) 

int main(){
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack P(size);

    int x;
    for(int i = 0; i < size; i++){
        cout << "Enter a number: ";
        cin >> x;
        P.Push(x);
    }
    P.Push(100);

    int *v;
    v = P.Peek();
    cout << "The top of the stack is: " << *v << endl; //We use the dereference operator to get the value of the pointer

    while (P.isEmpty()){
        cout << P.Pop()->num << endl; //We use the dereference operator to get the value of the pointer
    }

    return 0;
}