#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    // Constructor to initialize the node with a given value
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node

    // Constructor to initialize head and tail
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // If there are no nodes in the linked list
        if (head == nullptr) {
            head = newNode; // Set the new node as head
            tail = newNode; // Set the new node as tail
            return;
        }
        
        // Set the next of the current tail to the new node
        tail->next = newNode;
        
        // Update tail to be the new node
        tail = newNode;
    }

    void printValues() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        } else {
            Node* current = head;
            while (current != nullptr) {
                cout << current->value << ' '; // Print the value of the current node
                current = current->next; // Move to the next node
            }
            cout << '\n';
        }
    }

    // Destructor to clean up the list and free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current; // Free the current node
            current = nextNode; // Move to the next node
        }
    }
};

int main() {
    // Hardcoded input values
    int values[] = {2, 32, 23, 53}; // Example values
    int n = sizeof(values) / sizeof(values[0]); // Get the number of elements
    
    LinkedList* list = new LinkedList(); // Create a new linked list
    
    // Insert hardcoded values into the linked list
    for (int i = 0; i < n; i++) {
        int x = values[i]; // Get each value from the hardcoded array
        list->insertAtEnd(x); // Insert the value at the end of the list
    }

    // Print the values in the linked list
    cout << "Values in the linked list: ";
    list->printValues();

    // Clean up dynamically allocated LinkedList
    delete list; 
    return 0;
}

/*
Hardcoded input values:
2, 32, 23, 53

Expected Output:
Values in the linked list: 2 32 23 53
*/
