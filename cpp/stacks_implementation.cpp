#include <iostream>
using namespace std;

class Stack {
private:
    int max_size;        // Maximum size of the stack
    int* stack_array;    // Array to store stack elements
    int top;             // Index of the top element

public:
    Stack(int size) {
        max_size = size;
        stack_array = new int[max_size];
        top = -1;  // Initialize top as -1 to indicate an empty stack
    }

    ~Stack() {
        delete[] stack_array;
    }

    bool is_empty() {
        return top == -1;  // If top is -1, the stack is empty
    }

    bool is_full() {
        return top == max_size - 1;  // If top is at the maximum index, the stack is full
    }

    void push(int value) {
        if (is_full()) {
            cout << "Stack overflow! Cannot push " << value << ".\n";
            return;
        }

        // Increment top and add the value to the stack_array
        top++;
        stack_array[top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack underflow! Stack is empty.\n";
            return -1;  // Return a sentinel value to indicate underflow
        }

        int popped_value = stack_array[top];  // Get the top element
        top--;  // Decrement top to remove the element
        return popped_value;
    }
};

int main() {
    Stack myStack(5);  // Create a stack with a maximum size of 5

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    myStack.push(4);
    myStack.push(5);
    myStack.push(6);  // This will result in a stack overflow

    return 0;
}
