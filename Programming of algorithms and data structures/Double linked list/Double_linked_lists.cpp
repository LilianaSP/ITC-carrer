#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *prev, *next;
};

// Insert a node at the beginning of the list
// Complexity - O(1)
Node *insert_node_begin(Node *head, int val)
{
    Node *new_node = new Node; // Create a new node
    new_node->val = val;       // Set the value of the new node
    new_node->next = head;     // Set the next pointer of the new node to the head
    new_node->prev = NULL;     // Set the previous pointer of the new node to NULL

    // If the list is not empty, set the previous pointer of the head to the new node
    if (head)
    {
        new_node->next = head;
        head->prev = new_node;
    }
    return new_node;
}

// Insert a node at the end of the list
// Complexity - O(n)
Node *insert_node_end(Node *head, int val)
{
    Node *new_node = new Node; // Create a new node
    new_node->val = val;       // Set the value of the new node
    new_node->next = NULL;     // Set the next pointer of the new node to NULL

    // If the list is not empty, set the next pointer of the last node to the new node
    if (head)
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
    else
    {
        // else If the list is empty, set the new node as the head
        new_node->prev = NULL;
        head = new_node;
    }
    return head;
}

// Insert a node after a given node
// Complexity - O(n)
Node *insert_node_after(Node *head, int val, int after)
{
    Node *new_node = new Node; // Create a new node
    new_node->val = val;       // Set the value of the new node

    // If the list is not empty...
    if (head)
    {
        Node *current = head;

        // Find the given node
        while (current->val != after)
        {
            current = current->next;
        }

        // Set the next pointer of the new node to the next pointer of the given node
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node;

        // If the given node is not the last node, set the previous pointer of the next node to the new node
        if (new_node->next)
        {
            new_node->next->prev = new_node;
        }
    }
    return head;
}

// Search position of a node
// Complexity - O(n)
Node *search_position(Node *head, int pos)
{
    Node *current = head; // Set the current node to the head
    int i = 0;            // Set the position counter to 0
    while (i < pos)       // While the position counter is less than the given position
    {
        current = current->next; // Set the current node to the next node
        i++;                     // Increment the position counter
    }

    return current;
}

// Search value of a node
//  Complexity - O(n)
Node *search_value(Node *head, int val)
{
    Node *current = head;       // Set the current node to the head
    while (current->val != val) // While the value of the current node is not equal to the given value
    {
        current = current->next; // Set the current node to the next node
    }

    return current;
}

// Update a value of a node
// Complexity - O(n)
void update_value(Node *head, int val, int new_val)
{
    Node *current = head; // Set the current node to the head

    // While the value of the current node is not equal to the given value
    while (current->val != val)
    {
        current = current->next;
    }

    // Set the value of the current node to the new value
    current->val = new_val;
}

// Delete a node
// Complexity - O(n)
Node *delete_node(Node *head, int val)
{
    // If the list is not empty...
    if (head)
    {
        Node *current = head; // Set the current node to the head

        // While the value of the current node is not equal to the given value
        while (current->val != val)
        {
            current = current->next;
        }

        if (current->prev)
        {                                        // If the previous node exists
            current->prev->next = current->next; // Set the next pointer of the previous node to the next pointer of the current node
        }
        else
        {
            head = current->next; // else Set the head to the next node
        }
        if (current->next)
        {                                        // If the next node exists
            current->next->prev = current->prev; // Set the previous pointer of the next node to the previous pointer of the current node
        }

        delete current; // Delete the current node
    }
    return head;
}

// Print the list
// Complexity - O(n)
void print_double_linked_list(Node *head)
{
    Node *current = head; // Set the current node to the head

    cout << "NULL <- "; // Print the NULL pointer

    while (current)
    {                                    // While the current node exists
        cout << current->val << " <-> "; // Print the value of the current node
        current = current->next;         // Set the current node to the next node
    }
    cout << " NULL " << endl; // Print the NULL pointer
}

int main()
{
    Node *head = NULL; // Set the head to NULL

    cout << endl;
    cout << "++++ The program begins ++++" << endl;
    // Insert nodes at the beginning of the list
    head = insert_node_begin(head, 5);
    head = insert_node_begin(head, 4);
    head = insert_node_begin(head, 7);
    head = insert_node_begin(head, 6);
    head = insert_node_begin(head, 3);

    print_double_linked_list(head); // Print the list

    // Insert nodes at the end of the list
    head = insert_node_end(head, 2);
    head = insert_node_end(head, 1);
    head = insert_node_end(head, 8);
    head = insert_node_end(head, 10);
    head = insert_node_end(head, 9);

    print_double_linked_list(head); // Print the list

    // Insert nodes after a given node
    head = insert_node_after(head, 11, 5);
    head = insert_node_after(head, 12, 10);
    head = insert_node_after(head, 13, 1);

    print_double_linked_list(head); // Print the list

    // Search position of a node
    Node *node = search_position(head, 10);
    cout << "Position 10: " << node->val << endl;

    // Search value of a node
    node = search_value(head, 1);
    cout << "Value 1: " << node->val << endl;

    // Update a value of a node
    update_value(head, 2, 11);
    print_double_linked_list(head); // Print the list

    // Delete a node
    head = delete_node(head, 10);
    print_double_linked_list(head); // Print the list

    cout << "++++ The program ends ++++" << endl;

    return 0;
}