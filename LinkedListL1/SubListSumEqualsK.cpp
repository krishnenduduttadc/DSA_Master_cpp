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

    cout << "Linked List:\n";
    printList(head);

    int k = 7;
    cout << "\nPairs whose sum is " << k << ":\n";
    sublist(head, k);

    deleteList(head);

    return 0;
}
