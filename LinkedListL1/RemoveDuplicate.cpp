#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

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
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(5);

    cout << "Original Linked List:" << endl;
    printList(head);

    deleteDups(head);

    cout << "Linked List after removing duplicates:" << endl;
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
