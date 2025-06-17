#include <iostream>
using namespace std;

// Define a plain struct instead of a class
struct Node {
    int data;
    Node* next;
};

// Globals to mirror the original logic
int n;
Node* mid;

// Allocate and initialize a new list node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

// Recursive utility to find midpoint (mirrors original logic exactly)
void midpoint_util(Node* head) {
    if (head == nullptr) {
        // When you hit the end, fold n back to half its value
        n = n / 2;
        return;
    }
    n = n + 1;
    midpoint_util(head->next);
    n = n - 1;
    if (n == 0) {
        mid = head;
    }
}

// Public API to find midpoint
Node* midpoint(Node* head) {
    mid = nullptr;
    n = 1;
    midpoint_util(head);
    return mid;
}

int main() {
    // Build the sample list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Find and print the midpoint's data
    Node* result = midpoint(head);
    cout << result->data << endl;  // Expected output: 3

    return 0;
}
