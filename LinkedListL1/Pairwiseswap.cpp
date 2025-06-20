#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);

    cout << "Linked list before calling pairwiseSwap():\n";
    printList(head);

    head = pairWiseSwap(head);

    cout << "Linked list after calling pairwiseSwap():\n";
    printList(head);

    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
