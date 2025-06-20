#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node* deleteNode(Node* head, int x) {
    if (head == nullptr || x <= 0) return head; // If list is empty or position is invalid

    Node* d = head;

    for (int i = 1; i < x; i++) {
        d = d->next;
        if (d == nullptr) return head; // If position x is out of bounds
    }

    if (d->prev == nullptr) {
        head = d->next;
        if (head != nullptr) head->prev = nullptr;
    }
    else if (d->next == nullptr) {
        d->prev->next = nullptr;
    }
    else {
        d->prev->next = d->next;
        d->next->prev = d->prev;
    }

    d->next = nullptr;
    d->prev = nullptr;
    delete d;

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original List:" << endl;
    printList(head);

    head = deleteNode(head, 3);
    cout << "List after deleting node at position 3:" << endl;
    printList(head);

    head = deleteNode(head, 1);
    cout << "List after deleting node at position 1:" << endl;
    printList(head);

    head = deleteNode(head, 3); // Note: current length is 3 after deletions
    cout << "List after deleting node at position 3:" << endl;
    printList(head);

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
