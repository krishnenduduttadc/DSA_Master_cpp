#include <iostream>
using namespace std;

// Define Node using struct (instead of class)
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

// Function to find all pairs of nodes whose sum is k
void sublist(Node* head, int k) {
    Node* i = head;
    while (i != nullptr) {
        Node* j = i;
        while (j != nullptr) {
            if (i->data + j->data == k) {
                cout << i->data << " and " << j->data << " equals " << k << endl;
            }
            j = j->next;
        }
        i = i->next;
    }
}

// Function to delete the entire linked list and free memory
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Creating the linked list: 1 -> 2 -> 2 -> 3 -> 4 -> 3 -> 5 -> null
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(5);

    // Print the original list
    cout << "Linked List:\n";
    printList(head);

    // Call the function with target sum
    int k = 7;
    cout << "\nPairs whose sum is " << k << ":\n";
    sublist(head, k);

    // Free memory
    deleteList(head);

    return 0;
}
