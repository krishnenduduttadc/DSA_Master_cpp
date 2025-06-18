#include <iostream>
using namespace std;

// Node structure
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

// Function to print the list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to perform pairwise swap
Node* pairWiseSwap(Node* node) {
    if (node == nullptr || node->next == nullptr)
        return node;

    Node* remaining = node->next->next;
    Node* newHead = node->next;
    newHead->next = node;
    node->next = pairWiseSwap(remaining);
    return newHead;
}

int main() {
    // Create the linked list manually: 1->2->3->4->5->6->7
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);

    // Print original list
    cout << "Linked list before calling pairwiseSwap():\n";
    printList(head);

    // Perform pairwise swap
    head = pairWiseSwap(head);

    // Print list after swap
    cout << "Linked list after calling pairwiseSwap():\n";
    printList(head);

    // Clean up memory
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
