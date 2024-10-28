
#include <bits/stdc++.h>
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

    // Function to delete a node with a given value
    void deleteNode(int value) {
        // If the list is empty
        if (head == nullptr) {
            return;
        }

        // If the node to be deleted is the head node
        if (head->value == value) {
            Node* targetNode = head;
            head = head->next; // Move head to the next node
            delete targetNode; // Free memory of the old head
            return; // Exit after deletion
        }

        Node* iter = head;
        
        // Traverse the list to find the node to delete
        while (iter->next != nullptr) {
            if (iter->next->value == value) {
                Node* targetNode = iter->next; // The node to delete
                iter->next = iter->next->next; // Bypass the node
                delete targetNode; // Free memory
                return; // Exit after deletion
            }
            iter = iter->next; // Move to the next node
        }
    }

    // Function to insert a new node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
        }
        iter->next = newNode;
    }

    // Function to print the linked list
    void printList() {
        Node* iter = head;
        while (iter != nullptr) {
            cout << iter->value << " ";
            iter = iter->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    
    cout << "Original list: ";
    ll.printList();
    
    ll.deleteNode(3);
    cout << "After deleting 3: ";
    ll.printList();
    
    ll.deleteNode(1);
    cout << "After deleting 1 (head): ";
    ll.printList();
    
    ll.deleteNode(5); // Try to delete a non-existent value
    cout << "After trying to delete 5 (not in list): ";
    ll.printList();

    return 0;
}
