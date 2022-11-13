#include <iostream>

using namespace std;

struct Linked_List{
    int data;
    Linked_List *next; //Pointer to the next node
};
    



int main(){
    Linked_List *head; //pointer to the first node of integers
    Linked_List *new_node = new Linked_List();
    new_node -> data = 8; //We assign the data to the node
    new_node -> next = NULL; //We assign the pointer to the next node to NULL
    head = new_node; //We assign the pointer to the first node to the new node

    Linked_List *new_node1 = new Linked_List(); //We create a new node
    new_node1 -> data = 10; //We assign the data to the node
    new_node1 -> next = NULL; //We assign the pointer to the next node to NULL
    head->next = new_node1; //We assign the pointer to the next node to the new node
    
    Linked_List *temp = head; //We create a temporary pointer to the first node

    while(temp != NULL){ //We create a while loop to print the data of the nodes
        cout << temp -> data << "<-" << endl;
        temp = temp->next;
    }
    cout << endl;
   
    


    








    return 0;
}