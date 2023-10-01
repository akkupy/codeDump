#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Append a new node to the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Prepend a new node to the beginning of the list
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Delete a node with a given value from the list
    void deleteNode(int data) {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                if (current == head) {
                    head = current->next;
                    if (head) {
                        head->prev = nullptr;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Display the elements of the list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.prepend(0);

    dll.display(); // Output: 0 <-> 1 <-> 2 <-> 3 <-> nullptr

    dll.deleteNode(2);

    dll.display(); // Output: 0 <-> 1 <-> 3 <-> nullptr

    return 0;
}
