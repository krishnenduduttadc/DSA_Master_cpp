#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

bool deleteNode(Node* givenNode) {
    if (givenNode == nullptr || givenNode->next == nullptr) {
        return false;
    }

    Node* next = givenNode->next;
    givenNode->data = next->data;
    givenNode->next = next->next;

    delete next; 

    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(5);

    printList(head);

    deleteNode(head->next->next);

    printList(head);

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
