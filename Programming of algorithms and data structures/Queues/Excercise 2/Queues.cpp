#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> queue){
    // Print the queue
    //We iterate through the queue while it is not empty and then print the front of the queue
    while(!queue.empty()){
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;

}

int main(){
    queue<int> myQueue;
    //Push function is to add elements at the end of the queue
    //We push 3 elements of my queue
    cout << endl;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    //Pop function is to remove elements from the front of the queue

    cout << "Size is: " << myQueue.size() << endl;

    //Front function is to get the first element of the queue
    cout << "First element is: " << myQueue.front() << endl;

    //Back function is to get the last element of the queue
    cout << "Last element is: " << myQueue.back() << endl;

    cout << "My queue is: " << endl;
    printQueue(myQueue);
}