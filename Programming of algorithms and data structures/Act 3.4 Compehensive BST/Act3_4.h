#ifndef Act3_4_h
#define Act3_4_h
#pragma once 
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;

// ------------------- NODE Class-------------------
/// 
template<class T>
struct Node {
    T data;
    Node<T> *next;
    Node(T data);
    Node(T data, Node<T> *next);
};

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* next) {
    this->data = data;
    this->next = next;
}

// ------------------- Node2 Class-------------------
template<class T>
struct Node2 {
    T data;
    Node2<T> *next;
    Node2<T> *prev;
    Node2(T data);
    Node2(T data, Node2<T> *next, Node2<T>* prev);
};

template<class T>
Node2<T>::Node2(T data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template<class T>
Node2<T>::Node2(T data, Node2<T>* next, Node2<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}

//--------------------- Queue Class ---------------------
template<class T>
class Queue{
    private:
        Node<T> *head;
        Node<T> *tail;
        int index;
        int size;
    public:
        Queue();

        T dequeue();
        void enqueue(T data);

        T front();
        T back();
        
        int getSize() { return size; };
        void clear();

        bool isEmpty(){return size == 0;};
        int getIndex(){return index;};

        void print();
};
//Default constructor
//Insert head and tail as NULL and size as 0
//Time complexity: O(1)
template<class T>
Queue<T>::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

//Function dequeue() is used to remove the first element of the queue
//Time complexity: O(1)
template<class T>
T Queue<T>::dequeue(){
   if(!isEmpty()){ //if the queue is not empty it will remove the first element
        Node<T> *temp = head;
        T data = temp->data;
        head = head->next; //head will be the next element and the first element will be removed
        delete temp; //delete the first element
        size--;
        return data; //return the data of the first element
    }
    throw runtime_error("EMPTY\n");
}

//Function enqueue() is used to add an element to the queue
//Time complexity: O(1)
template<class T>
void Queue<T>::enqueue(T data){
    if(!isEmpty()){ //if the queue is not empty it will add the element to the end of the queue
        tail->next = new Node<T>(data); //the next element of the tail will be the new element
        tail = tail->next; //the tail will be the new element
        size++; //increase the size of the queue
    } else{
        head = new Node<T>(data); //if the queue is empty the new element will be the head and the tail
        tail = head; //the tail will be the head
        size++; //increase the size of the queue
    }
}

//Function front() is used to get the first element of the queue
//Time Complexity: O(1)
template<class T>
T Queue<T>::front(){
    if(!isEmpty()){
        return head->data; //return the data of the first element
    }
    throw runtime_error("EMPTY\n");
}

//Function back() is used to get the last element of the queue. It will return the tail as the last element
//Time Complexity: O(1)
template<class T>
T Queue<T>::back(){
    if(!isEmpty()){
        return tail->data; //return the data of the last element
    }
    throw runtime_error("EMPTY\n");
}

//Function clear() is used to clear the queue. It will delete all the elements of the queue
//Time Complexity: O(n)
template<class T>
void Queue<T>::clear(){
    if(!isEmpty()){
        while(size > 0){ //while the size of the queue is greater than 0 it will remove the first element
            if(size > 1){ //if the size is greater than 1 it will remove the first element
                Node<T> *temp = head; //create a temp node to store the head
                head = head->next;
                delete temp;
                size--;
            } else{
                head = tail = NULL ; //if the size is 1 it will delete the head and the tail
                size--; //decrease the size of the queue
            }
        }
        
    } else{
        cout << "Empty Queue" << endl;
    }
}

//Function print() is used to print the elements of the queue
//Time Complexity: O(n)
template<class T>
void Queue<T>::print(){
    if(!isEmpty()){
        Node<T> *temp = head;
        while(temp != NULL){
            cout << temp->data << " "; //print the data of the elements
            temp = temp->next; //go to the next element
        }
        cout<<endl;
    } else{
        cout << "Empty Queue"<<endl;
    }
}

//---------------------- IP Registry Class ----------------------
//This class will store the IP addresses and the number of times they have been accessed
//It will use a map to store the IP addresses and the number of times they have been accessed the most
//It will use a queue to store the IP addresses and the number of times they have been accessed the least 
//It will use a doubly linked list to store the IP addresses and the number of times they have been accessed in order
//It will use a vector to store the IP addresses and the number of times they have been accessed the most

struct IPRegistry{
    //we create our variables
    string ip;
    int access_frec = 0;
    vector<string> errors;
    vector<string> ports;


    //we create our constructors and functions
    //We use the stringOfErrors function to store the errors in a vector
    //Time Complexity: O(1)
    string stringOfErrors(){
        string output = "";
        // Define an map iterator and point to beginning of map 
        map<string, int> accesed_IPs; 
        // Traverse vector vec to check if the current element is present or not 
        for (int i = 0; i< errors.size(); i++) { 
            // If the current element is not found then insert current element with frequency 1 
            if (accesed_IPs.find(errors[i]) == accesed_IPs.end()) { 
                accesed_IPs[errors[i]] = 1; 
            } 
            // Else update the frequency 
            else { 
                accesed_IPs[errors[i]]++; //increase the frequency of the error
            } 
        } 

        // Traverse the map to print the frequency 
        //Time Complexity: O(n)
        output +="{";
        int counter = accesed_IPs.size();
        for (auto& it : accesed_IPs) { 
            output+= '\u0022'+it.first + '\u0022'+':'+ to_string(it.second); //add the error and the frequency to the output 
            if(counter > 1){
                output += ",";
            }
            counter--; //decrease the counter
        }
        output+="}";
        return output; 
    }

    //We use the stringOfPorts function to store the ports in a vector
 
    //obtener string de los errores de un map de frecuencia
    //To obtain the most used port we will use a map
    //Time Compexity O(n)
    string stringOfPorts(){
        string output = "";
        // Define an map to store the frequency of each port
        map<string, int> frequencies; 
        // Traverse vector vec check if current element is present or not 
        for (int i = 0; i < ports.size(); i++) { 
    
            // If the current element is not found then insert the current element with frequency 1 
            //Time Copmlexity O(1)
            if (frequencies.find(ports[i]) == frequencies.end()) { 
                frequencies[ports[i]] = 1; 
            } 
            // Else update the frequency 
            else { 
                frequencies[ports[i]]++; 
            } 
        } 

        // Traverse the map to print the frequency 
        output += "{";
        int counter = frequencies.size(); //counter to know when to add a comma
        for (auto& it : frequencies) { 
            output+= '\u0022'+it.first +'\u0022'+ ": "+ to_string(it.second); //add the port and the frequency to the output
            if(counter > 1){
                output += ",";
            }
            counter--;
        }
        output+="}";
        return output; 
    }

    //Overload the operator << to print the IPRegistry
    friend ostream &operator<<( ostream &output, IPRegistry &D ) { 
        cout<<"IP: " << D.ip << endl;
        cout<<"Frequency: " << D.access_frec <<endl;
        cout<<"Ports:" <<D.stringOfPorts() <<endl;
        cout<<"Errors:" <<D.stringOfErrors() <<endl;
        return output;            
    }
    
    //Function to obtain the string IP
    //Time complexity O(n)
    string stringOfIps(){
        string output  = "";
        string new_string = to_string(access_frec);
        output += string("{")+'"'+"IP"+'"'+":"+'"'+ip +'"'+","+'"'+"Ports"+'"'+":"+stringOfPorts()+"," +'"'+"Frequency"+'"'+":"+new_string+","+'"'+"Errors"+'"'+":"+stringOfErrors()+"}"+"\n";
        return output;   
    }

    //Overload of mayor, minor, equal, minor or equal, mayor or equal

    bool operator <( const IPRegistry& x ) const{
        if(ip < x.ip){return true;}
        else{return false;}
    }
    bool operator >( const IPRegistry& x ) const{
        if(ip < x.ip){return true;}
        else{return false;}
    }
    bool operator <=( const IPRegistry& x ) const{
        if(ip <= x.ip){return true;}
        else{return false;}
    }
    bool operator >=( const IPRegistry& x ) const{
        if(ip >= x.ip){return true;}
        else{return false;}
    }
    bool operator ==( const IPRegistry& x ) const{
        if(ip == x.ip){return true;}
        else{return false;}
    }
    bool operator !=( const IPRegistry& x ) const{
        if(ip != x.ip){return true;}
        else{return false;}
    }
    
    //overload the operator < to compare the frequency of the IPs
    //For the heaps
    bool minor( const IPRegistry& x ) const{
        if(access_frec < x.access_frec){return true;}
        else{return false;}
    }

    bool minorEqual( const IPRegistry& x ) const{
        if(access_frec <= x.access_frec){return true;}
        else{return false;}
    }

    bool major( const IPRegistry& x ) const{
        if(access_frec > x.access_frec){return true;}
        else{return false;}
    }

    bool majorEqual( const IPRegistry& x ) const{
        if(access_frec >= x.access_frec){return true;}
        else{return false;}
    }


    bool equal( const IPRegistry& x ) const{
        if(access_frec == x.access_frec){return true;}
        else{return false;}
    }
};

//--------------------Linked List--------------------
//Clase doubly linked list
//We use a doubly linked list to store the IPs
template<class T>
class DoublyLinkedList {
private:
    Node2<T>* head;
    Node2<T>* tail;
    int size;
    void mergeSort(int ini, int fin);
    void merge(int ini, int mid, int fin);
public:
    DoublyLinkedList();
    void operator=(initializer_list<T> list);
    void operator=(DoublyLinkedList<T> list);
    T& operator[](int index);
    void addFirst(T data);
    void addLast(T data);
    bool deleteAllData(T data); 
    bool deleteByPos(int index); 
    T getData(int index); 
    void updateByPos(int index, T newData);
    void updateDataByElement(T data, T newData);
    void insertbyPos(int index, T newData);
    void duplicate();
    void removeDuplicates();
    int findData(T data);
    void sort();
    void clear();
    void print();
    void printReverse();
    bool isEmpty();
    int getSize();
    bool AlreadyExists(IPRegistry registry);
    int getIndex(IPRegistry registry);
    string stringOfIps();
    void printTopfive();
};

//Default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

//Overload the operator {} to add elements to the list
//Time Complexity: O(n)
template<class T>
T& DoublyLinkedList<T>::operator[](int index) { //We use the operator [] to access the data in the list
    if (index >= 1 && index <= size) { //We use a for loop to iterate through the list
        if (index <= size / 2) {
            Node2<T>* aux = head;
            int i = 1; //We use a counter to know when we have reached the index
            while (aux != NULL) {
                if (i == index) {
                    return aux->data; //We return the data in the node
                }
                aux = aux->next;
                i++;
            }
        } else {
            Node2<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) { //it goes through the list
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev; //goes backwards through the list for the last half 
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

//Overload the operator to copy the elements of a list to another or to another vector
//Time Complexity: O(n)
template<class T>
void DoublyLinkedList<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T i : list) {
            addLast(i); //add the elements to the list one by one
        }
    } else {
        throw runtime_error("Error: DoublyLinkedList no esta vacia");   
    }
}

//Overload the operator = to copy the elements of a list to another
//Time Complexity O(n)
template<class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list) {
    clear();
    for (int i=1; i<=list.size; i++) {
        addLast(list[i]);
    }

}

//We use the addFirst method to add an element to the beginning of the list
//We create a new node and we assign the data to it
//We check if the list is empty
//If it is empty we assign the head and tail to the new node
//If it is not empty we assign the new node to the head and the head to the new node
//Time cComplexity: O(1)
template<class T>
void DoublyLinkedList<T>::addFirst(T data) {
    if (!isEmpty()) {
        head->prev = new Node2<T>(data, head, NULL); 
        head = head->prev;
    } else {
        head = new Node2<T>(data);
        tail = head;
    }
    size++;
}

//We use the addLast method to add an element to the end of the list
//We create a new node and we assign the data to it
//We check if the list is empty
//If it is empty we assign the head and tail to the new node
//If it is not empty we assign the new node to the tail and the tail to the new node
//Time Complexity O(1)
template<class T>
void DoublyLinkedList<T>::addLast(T data) {
    if (!isEmpty()) {
        tail->next = new Node2<T>(data,NULL, tail);
        tail = tail->next;
    } else {
        tail = new Node2<T>(data);
        head = tail;
    }
    size++;
}

//We use the deleteData method to delete an element from the list
//We create a new node and we assign the head to it
//We use a while loop to iterate through the list
//We check if the data is equal to the data of the node
//If it is equal we check if the node is the head
//If it is the head we assign the head to the next node
//If it is not the head we assign the next node to the previous node
//We delete the node and we return true
//If it is not equal we assign the next node to the current node
//If we reach the end of the list we return false
//Time Copmlexity: O(n)
template<class T>
bool DoublyLinkedList<T>::deleteAllData(T data) {
    if (!isEmpty()) {
        if (head->data == data) {
            Node2<T>* aux = head;
            head = aux->next;
            head->prev = NULL;
            delete aux; // Libera espacio de memoria
            size--;
            if (head == NULL) {
                tail = NULL;
            }
            return true;
        } else {
            if (head->next != NULL) {
                Node2<T>* aux = head->next;
                Node2<T>* prev = head;
                while (aux != NULL) {
                    if (aux->data == data) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                }
            }
        }
    }
    return false;
}

//We use the deleteAt method to delete an element from the list
//We create a new node and we assign the head to it
//We use a for loop to iterate through the list
//We use a counter to know when we have reached the index
//We check if the node is the head
//If it is the head we assign the head to the next node
//If it is not the head we assign the next node to the previous node
//We delete the node and we return true
//If we reach the end of the list we return false
//We throw an exception if the index is invalid
//We throw an exception if the list is empty
template<class T>
bool DoublyLinkedList<T>::deleteByPos(int index) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            Node2<T>* aux = head;
            head = aux->next;
            if (head == NULL) {
                tail = NULL;
            } else {
                head->prev = NULL;
            }
            delete aux;
            size--;
            return true;
        } else {
            if (head->next != NULL) {
                Node2<T>* aux = head->next;
                Node2<T>* prev = head;
                int i = 2;
                while (aux != NULL) {
                    if (i == index) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                    i++;
                }
            }
        }
    }
    return false;
}


//getData
//obtiene data por indice
//O(n)
template<class T>
T DoublyLinkedList<T>::getData(int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            Node2<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            Node2<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev;
                i--;
            }
            
        }
    }
    throw out_of_range("Invalid position");
}

//We use the updateByPos method to update an element from the list
//Time Complexity: O(n)
template<class T>
void DoublyLinkedList<T>::updateByPos(int index, T newData) {
    if (index >= 1 && index <= size) { 
        if (index <= size/2) { // We start from the head to the tail
            Node2<T>* aux = head;
            int i = 1;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux->next;
                i++;
            }
        } else {
            Node2<T>* aux = tail; // We start from the tail to the head
            int i = size;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux-> prev; // We go backwards in the list
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

//we use the updateData method to update an element from the list
//Time Complexity: O(n)
template<class T>
void DoublyLinkedList<T>::updateDataByElement(T data, T newData) {
    Node2<T>* aux = head;
    while(aux != NULL) {
        if (aux->data == data) { // We check if the data is equal to the data of the node
            aux->data = newData; // We update the data if it is equal
            return;
        }
        aux = aux->next;
    }
    throw out_of_range("Data not found");
}

//The function insertbyPos is a method that inserts an element in the list and returns true if it was successful
//Time Complexity: O(n)
template<class T>
void DoublyLinkedList<T>::insertbyPos(int index, T newData) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            head->prev = new Node2<T>(newData,head,NULL);
            head = head->prev;
            size++;
            return;
        } else {
            if (index == size) {
                tail->next = new Node2<T>(newData, NULL, tail);
                tail = tail->next;
                size++;
                return;
            } else {
                Node2<T>* aux = head->next;
                Node2<T>* prev = head;
                int i = 2;
                while(aux->next != NULL) {
                    if (i == index) {
                        prev->next = new Node2<T>(newData,aux,prev); // We create a new node and we assign the next node to it
                        size++;
                        size++;
                        return;
                    }
                    prev = aux;
                    aux = aux->next;
                    i++;
                }
            }
        }
    }
    throw out_of_range("Invalid position");
}

//we use the merge method to merge two lists
//It is a helper for the sort function
//Time complexity: O(n)
template<class T>
void DoublyLinkedList<T>::merge(int _start, int mid, int _end) {
    Queue<T> listLeft;
    Queue<T> listRight;
    int pos,f1,f2,i,j;
    pos = _start;
    f1 = mid - _start + 1;
    f2 = _end - mid;   
    for (i=1;i<=f1;i++) {
        listLeft.enqueue(getData(_start+i-1));
    }
    for (j=1;j<=f2;j++) {
        listRight.enqueue(getData(mid+1+j-1));
    }
    i = 1;
    j = 1;
    while (i<=f1 && j<=f2) {
        if (listLeft.front()<=listRight.front()) {
            updateByPos(pos,listLeft.dequeue());
            i++;
        } else {
            updateByPos(pos,listRight.dequeue());
            j++;
        }
        pos++;
    }
    while (i<=f1) {
        updateByPos(pos,listLeft.dequeue());
        i++;
        pos++;
    }
    while (j<=f2) {
        updateByPos(pos,listRight.dequeue());
        j++;
        pos++;
    }
}

//Function mergeSort
//funcion helper to sort our list
//Time Complexity: O(n log n)
template<class T>
void DoublyLinkedList<T>::mergeSort(int _start, int _end) {
    if (_start < _end) {
        int mid = (_start + _end) / 2;
        mergeSort(_start,mid);
        mergeSort(mid+1,_end);

        merge(_start,mid,_end);
    }
}

//Function sort
//O(n log n)
template<class T>
void DoublyLinkedList<T>::sort() {
    mergeSort(1,size);
}

//We use the findData method to find an element in the list
//Time complexity: O(n)
template<class T>
int DoublyLinkedList<T>::findData(T data) {
    int start_pos = 1;
    int final_pos = size;
    int middle_pos = (start_pos + final_pos) / 2;
    bool found = false;
    sort();
    while (start_pos <= final_pos && !found) {
        if (data < getData(middle_pos)) {
            final_pos = middle_pos - 1;
            
        } else {
            if (data > getData(middle_pos)) {
                start_pos = middle_pos + 1;
                
            } else {
                if (data == getData(middle_pos)) {
                    found = true;
                }
            }
        }
        middle_pos = (start_pos + final_pos) / 2;
        
    }
    if (found) {
        return middle_pos;
    } else {
        return -1;
    }
}


//Function print is used to print the data of the list
//Time COmplexity: O(n)
template<class T>
void DoublyLinkedList<T>::print() {
    Node2<T>* aux = head;
    for (int i=1; i<=size; i++) {
        cout << aux->data<<endl;
        aux = aux->next;
    }
}

//Function printTopFive is used to print the top five IPs of the list
template<class T>
void DoublyLinkedList<T>::printTopfive() {
    Node2<T>* aux = head;
    for (int i=1; i<=5; i++) {
        cout << aux->data<<endl;
        aux = aux->next;
    }
}


//We use the stringOfIps method to convert the list into a txt string
//Time complexity: O(n)
template<class T>
string DoublyLinkedList<T>::stringOfIps() {
    string output ="";
    output+=string("{")+'\u0022'+"IP-Registry"+'\u0022'+":[";
    Node2<T>* aux = head;
    for (int i=1; i<=size; i++) {
        output+= aux->data.stringOfIps();
        if(i<size){
            output+=",";
        }
        aux = aux->next;
    }
    output+="]}\n";
    return output;
}

//We use the existsIn method to verify if an element exists in the list
//Time complexity: O(n)
template <class T>
bool DoublyLinkedList<T>::AlreadyExists(IPRegistry registry){
    Node2<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data == registry){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

//We use the getIndex method to get the index of an element in the list
//Time complexity: O(n)
template <class T>
int DoublyLinkedList<T>::getIndex(IPRegistry registry){
    Node2<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data.ip == registry.ip){
            return i;
        }
        aux = aux->next;
    }
    return -1;
}



//We use the printReverse method to print the list in reverse
//Time complexity: O(n)
//We start from the last node and we go backwards
template<class T>
void DoublyLinkedList<T>::printReverse() {
    Node2<T>* aux = tail;
    for (int i=size; i>=1; i--) {
        cout << aux->data << " ";
        aux = aux->prev;
    }
    cout << endl;
}

//We use the clear method to delete the list
//Time complexity: O(n)
//We start from the first node and we go forward to delete each node
template<class T>
void DoublyLinkedList<T>::clear() {
    int i = 1;
    while (i<=size) {
        Node2<T>* aux = head;
        head = aux->next;
        delete aux;
        i++;
    }
    size = 0;
    tail = NULL;
}

//We use the isEmpty method to verify if the list is empty
//Time complexity: O(1)
template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

//We use the getSize method to get the size of the list
//Time complexity: O(1)
//We return the size of the list
template<class T>
int DoublyLinkedList<T>::getSize() {
    return size;
}

//--------------------------- PriorityQueue ---------------------------
template <class T>
class PriorityQueue{
private:
    DoublyLinkedList<T> heap;
    int size;
    void SortingBackwards(int start_index);
    void swap(int temp,int aux );
public:
    PriorityQueue();
    PriorityQueue(DoublyLinkedList<T> lista);
    bool isEmpty();
    void print();

    T remove();
};

//Default Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(){
    size = 0;
}

//We use the constructor with a linked list to create a priority queue
//Time complexity: O(n)
template <class T>
PriorityQueue<T>::PriorityQueue(DoublyLinkedList<T> list){
    if (!list.isEmpty()){
        heap = list;
        size = list.getSize();
        int index = size/2;
        SortingBackwards(index); //se hace un downsort por default

    }
    
}   

//We use the isEmpty method to verify if the priority queue is empty
//Time complexity: O(1)
template <class T>
bool PriorityQueue<T>::isEmpty(){
    return size==0; // true o false
}

//We use the swap method to swap the elements in the list from the indices
//Time complexity: O(1)
template <class T>
void PriorityQueue<T>::swap(int a, int b){
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

//We use the function downSort to sort the elements in the priority queue
//Time complexity: O(n^)

template <class T>
void PriorityQueue<T>::SortingBackwards(int index){
    while (index >= 1){ //if the index is greater than 1, otherwise we are done (0)
        int pos = index;
        while (pos*2 <= size){ 
            int s1 = pos*2;
            int s2 = pos*2+1;
            int max;
            if(s2> size){ //we compare both of them
                max = s1;
            }else{ //we compare the index data of both of them
                heap[s1].major(heap[s2]) ? max = s1: max = s2; 
            }
            if(heap[max].major(heap[pos]) ){ //we do the swap if one is greather than the other one
                swap(pos,max);
                pos = max;
            }else{
                pos=size;

            }
        }
        index--; 
    }
}


//We use the print method to print the priority queue
//Time complexity: O(n)
template<class T>
void PriorityQueue<T>::print(){
    heap.print();
}


//We use the remove method to remove the first element in the priority queue
//Time complexity: O(n)
template<class T>
T PriorityQueue<T>::remove(){
   if(!isEmpty()){
       T aux = heap[1];
       swap(1,size);
       heap.deleteByPos(size); //we eliminate the start index
       size--; //reduce the size
       SortingBackwards(1); //it sorts the elements according to the function SortingBackwards
       return aux;
   }else{
       throw runtime_error("HEAP IS EMPTY");
   }
}
#endif 







