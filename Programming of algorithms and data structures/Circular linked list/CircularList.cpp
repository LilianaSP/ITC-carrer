#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int val;
    Node *prev, *next;
};

Node* insert_node_begin(Node *head, int val){
    Node *new_node = new Node();
    new_node->val = val; // set the value of the new node
    new_node->prev = new_node->next = NULL; // set the next pointer of the new node to the head
    if(head){
        new_node -> next = head;
        head -> prev = new_node;
         // if the list is empty, set the head to the new node
    }
    return new_node;
}

Node* insert_node_end(Node *head, int val){
    // if the list is empty, insert the new node at the beginning
    
}

Node* insert_node_after(Node *head, int val){

}

Node* delete_node(Node *head, int val){

}









void print_double_linked_list(Node *head){
    cout << "NULL <-";
    Node *curr = head;
    while (curr != NULL){
        cout << curr->val << " <-> ";
        curr = curr->next;
        
    }
    cout << "NULL" << endl;
}

int main(){

    Node *head = NULL;
    head = insert_node_begin(head, 10);
    head = insert_node_begin(head, 20);
    print_double_linked_list(head);
    cout << head -> val << "Double linked list " << endl;

    
    return 0;
}