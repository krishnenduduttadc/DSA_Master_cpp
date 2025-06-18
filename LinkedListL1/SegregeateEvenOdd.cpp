#include <iostream>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->val = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to push a new node at the beginning
void push(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to segregate even and odd nodes
Node* segregateEvenOdd(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* dummyEven = createNode(-1);
    Node* dummyOdd = createNode(-1);
    Node* evenTail = dummyEven;
    Node* oddTail = dummyOdd;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->val % 2 == 0) {
            evenTail->next = curr;
            evenTail = evenTail->next;
        } else {
            oddTail->next = curr;
            oddTail = oddTail->next;
        }
        curr = curr->next;
    }

    evenTail->next = dummyOdd->next;
    oddTail->next = nullptr;

    Node* result = dummyEven->next;
    delete dummyEven;
    delete dummyOdd;
    return result;
}

// Clean up memory
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node* head = nullptr;

    // Linked list: 6 -> 9 -> 10 -> 11
    push(head, 11);
    push(head, 10);
    push(head, 9);
    push(head, 6);

    Node* result = segregateEvenOdd(head);

    cout << "List after segregating even and odd values:\n";
    printList(result);

    // Clean up memory
    deleteList(result);

    return 0;
}
