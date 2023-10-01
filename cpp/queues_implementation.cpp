#include <iostream>
using namespace std;

class Queue {
private:
    int max_size;         // Maximum size of the queue
    int* queue_array;     // Array to store queue elements
    int front;            // Index of the front element
    int rear;             // Index of the rear element
    int current_size;     // Current number of elements in the queue

public:
    Queue(int size) {
        max_size = size;
        queue_array = new int[max_size];
        front = 0;          // Initialize front as 0
        rear = -1;          // Initialize rear as -1
        current_size = 0;   // Initialize the current size as 0
    }

    ~Queue() {
        delete[] queue_array;
    }

    bool is_empty() {
        return current_size == 0;  // If current_size is 0, the queue is empty
    }

    bool is_full() {
        return current_size == max_size;  // If current_size is equal to the max size, the queue is full
    }

    void enqueue(int value) {
        if (is_full()) {
            cout << "Queue is full! Cannot enqueue " << value << ".\n";
            return;
        }

        rear = (rear + 1) % max_size;  // Circularly increment rear
        queue_array[rear] = value;
        current_size++;
        cout << "Enqueued " << value << " into the queue.\n";
    }

    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return -1;  // Return a sentinel value to indicate underflow
        }

        int dequeued_value = queue_array[front];
        front = (front + 1) % max_size;  // Circularly increment front
        current_size--;
        return dequeued_value;
    }
};

int main() {
    Queue myQueue(5);  // Create a queue with a maximum size of 5

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);  // This will result in a queue overflow

    return 0;
}
