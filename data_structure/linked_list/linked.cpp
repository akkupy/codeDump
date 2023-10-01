#include <iostream>

// Define the structure of a node in the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a node
    Node(int value) : data(value), next(nullptr) {}
};

// Define a class for the linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to print the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to delete a node with a specific value from the list
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            std::cout << "Value not found in the list." << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

int main() {
    LinkedList list;
    
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    
    std::cout << "Initial linked list: ";
    list.display();
    
    list.deleteNode(2);
    
    std::cout << "Linked list after deleting 2: ";
    list.display();
    
    return 0;
}
