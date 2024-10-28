#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node after the k-th node
    void insertAfterK(int value, int k) {
        Node* newNode = new Node(value);
        
        // If the list is empty, set the new node as head and return
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* current = head;
        
        // Iterate to the k-th node
        for (int i = 1; i < k && current != nullptr; i++) {
            current = current->next;
        }

        // If current is null, it means k is greater than the length of the list
        if (current == nullptr) {
            // Optionally: You can append the new node at the end instead
            delete newNode; // Free the memory since we can't insert
            cout << "Position exceeds the length of the list. Node not inserted." << endl;
            return;
        }
        
        // Insert the new node after the k-th node
        newNode->next = current->next; // Set next of new node to the next of current
        current->next = newNode; // Link current node to the new node
    }

    // Function to insert a new node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to print the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    
    cout << "Original list: ";
    ll.printList();
    
    ll.insertAfterK(4, 2); // Insert after the 2nd node
    cout << "After inserting 4 after 2nd node: ";
    ll.printList();
    
    ll.insertAfterK(5, 4); // Try to insert after the 4th node (which doesn't exist)
    cout << "After trying to insert 5 after 4th node: ";
    ll.printList();
    
    return 0;
}
