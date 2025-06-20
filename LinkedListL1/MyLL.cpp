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

void push(Node*& head, int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

int main() {
    Node* head = nullptr;

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
