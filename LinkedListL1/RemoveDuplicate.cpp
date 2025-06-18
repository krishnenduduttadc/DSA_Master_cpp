#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr)
            cout << " -> ";
        else
            cout << " -> null";
        current = current->next;
    }
    cout << endl;
}

// Function to remove duplicates (brute-force method, O(n^2))
void deleteDups(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* current = head;
    while (current != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* dup = runner->next;
                runner->next = dup->next;
                delete dup; // free memory
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    // Creating linked list: 1 -> 2 -> 2 -> 3 -> 4 -> 3 -> 5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(5);

    // Print original list
    cout << "Original Linked List:" << endl;
    printList(head);

    // Remove duplicates
    deleteDups(head);

    // Print updated list
    cout << "Linked List after removing duplicates:" << endl;
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
