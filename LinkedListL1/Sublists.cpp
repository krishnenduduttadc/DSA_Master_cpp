#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

void sublists(Node* head) {
    Node* i = head;
    while (i != nullptr) {
        Node* j = i;
        while (j != nullptr) {
            cout << j->data << " -> ";
            j = j->next;
        }
        cout << "null" << endl;
        i = i->next;
    }
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(5);

    cout << "Original Linked List:\n";
    printList(head);

    cout << "\nAll Sublists:\n";
    sublists(head);

    deleteList(head);

    return 0;
}
