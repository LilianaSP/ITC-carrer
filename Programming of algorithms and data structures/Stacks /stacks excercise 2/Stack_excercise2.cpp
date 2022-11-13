#include <iostream>
#include <stack>

using namespace std;

//The function ask for the top element of the stack and then pop it
//while the stack is not empty
void printStacksElements(stack<int> stack){
    while(!stack.empty()){
        cout << stack.top() << endl; //print the top element
        stack.pop(); //pop the top element
    }

}


int main(){
    //we create a stack
    //empty, size, push, pop, top
    stack<int> numbersStack;
    cout << endl; 
    //the function pop() receives only one parameter and it puts it on the top of the stack
    numbersStack.push(1); 
    numbersStack.push(2);
    numbersStack.push(3);

    //The function pop() eliminates the top element of the stack
    numbersStack.pop();
    

    //the function top() 

    /*if(numbersStack.empty()){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The stack is not empty" << endl;
    }

    cout <<"The stack size is: " << numbersStack.size() << endl;
    /*/
    printStacksElements(numbersStack);

    //Stack is LIFO collection -> Last In First Out

    //Creating my own stack
    cout <<endl;
    cout << "Creating my own stack" << endl;
    stack<int> myFirstStack;
    cout <<endl;
    
    //We use the function push() to add elements to my stack
    myFirstStack.push(23);
    myFirstStack.push(34);
    myFirstStack.push(45);
    myFirstStack.push(56);
    //We created a stack of 4 elements
    //we want to delete the top element in this case 56 -> LIFO

    myFirstStack.pop();
    //we want to print the stack
    printStacksElements(myFirstStack);










    return 0;
}