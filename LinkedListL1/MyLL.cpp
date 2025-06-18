#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Function to push a new element at the beginning of the list
void push(Node*& head, int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Main function
int main() {
    Node* head = nullptr;

    // Push elements to the list
    push(head, 11);
    push(head, 10);
    push(head, 9);
    push(head, 6);
    push(head, 4);
    push(head, 1);
    push(head, 0);

    cout << "Original Linked List:" << endl;
    printList(head);

    head = reverse(head);

    cout << "Reversed Linked List:" << endl;
    printList(head);

    return 0;
}
