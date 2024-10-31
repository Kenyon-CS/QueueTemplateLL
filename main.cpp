#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    // Node structure to represent each element in the queue
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}  // Constructor to initialize node with data
    };

    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to clean up memory
    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue method to insert an element at the rear of the queue
    void enqueue(T val) {
        Node* temp = new Node(val);  // Create a new node with the value
        if (rear == nullptr) {       // Queue is empty
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    // Dequeue method to remove an element from the front of the queue
    void dequeue() {
        if (front == nullptr) {  // Queue is empty
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Element deleted from queue: " << front->data << endl;
        front = front->next;

        if (front == nullptr) {  // If queue becomes empty after dequeue
            rear = nullptr;
        }
        
        delete temp;
    }

    // Display method to show all elements in the queue
    void display() const {
        if (front == nullptr) {  // Queue is empty
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Queue of integers
    Queue<int> intQueue;
    cout << "Integer Queue Created:" << endl;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.enqueue(40);
    intQueue.enqueue(50);
    intQueue.display();

    intQueue.dequeue();
    cout << "Integer Queue after one deletion:" << endl;
    intQueue.display();

    // Queue of strings
    Queue<string> stringQueue;
    cout << "\nString Queue Created:" << endl;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    stringQueue.enqueue("Queue");
    stringQueue.display();

    stringQueue.dequeue();
    cout << "String Queue after one deletion:" << endl;
    stringQueue.display();

    return 0;
}
