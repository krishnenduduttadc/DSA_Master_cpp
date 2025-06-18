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

    delete next; // Free memory of the node we deleted

    return true;
}

int main() {
    // Create a linked list with 7 hard-coded nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(5);

    printList(head);

    // Delete the third node
    deleteNode(head->next->next);

    printList(head);

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
