#include <iostream>

using namespace std;

class Node{
    public:
        int Value; // value of the node
        Node* next; // pointer to next node(element)
};

void PrintList(Node *n){
    while(n != NULL){
        cout << n->Value << endl;
        n = n->next;

    }


}

int main(){
    Node* head = new Node(); // create a new node
    Node* second = new Node(); // create a new node
    Node* third = new Node(); // create a new node

    head->Value = 1; // assign value to the node
    head-> next = second; // assign pointer to the next node

    second->Value = 2; // assign value to the node
    second-> next = third; // assign pointer to the next node

    third->Value = 3; // assign value to the node
    third-> next = NULL; // assign pointer to the next node (NULL) because it is the last node

    PrintList(head);






    return 0;
}