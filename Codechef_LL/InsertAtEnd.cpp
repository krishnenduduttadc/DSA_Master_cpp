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
    Node* head;

    // Constructor to initialize the head to nullptr
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        Node* current = head;
        
        // If there are no nodes in the linked list
        if (head == nullptr) {
            head = newNode; // Set the new node as the head
            return;
        }
        
        // Iterate to the end of the list
        while (current->next != nullptr) {
            current = current->next;
        }
        
        // Set the next of the last node to the new node
        current->next = newNode;
    }
    
    int getLastValue() {
        if (head == nullptr) {
            return -1; // Return -1 if the list is empty
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next; // Traverse to the end
            }
            return current->value; // Return the last node's value
        }
    }

    // Function to clean up the list and avoid memory leaks
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current; // Free memory of current node
            current = nextNode; // Move to the next node
        }
    }
};

int main() {
    // Hardcoded input
    int values[] = {2, 32, 23, 53}; // Example values
    int n = sizeof(values) / sizeof(values[0]); // Get the number of elements
    
    LinkedList* list = new LinkedList();
    
    for (int i = 0; i < n; i++) {
        int x = values[i]; // Get each value from the hardcoded array
        list->insertAtEnd(x);
        cout << "Last value after inserting " << x << ": " << list->getLastValue() << '\n';
    }

    // Clean up dynamically allocated LinkedList
    delete list;
    return 0;
}

/*
Hardcoded input values:
2, 32, 23, 53
*/

// Output Example:
// Last value after inserting 2: 2
// Last value after inserting 32: 32
// Last value after inserting 23: 23
// Last value after inserting 53: 53
