#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* push(Node* head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head_ref;
    head_ref = new_node;
    return head_ref;
}

void printAlternate(Node* node, bool isOdd) {
    if (node == nullptr) {
        return;
    }
    if (isOdd) {
        cout << node->data << " ";
    }
    printAlternate(node->next, !isOdd);
}

int main() {
    Node* head = nullptr;

    head = push(head, 10);
    head = push(head, 9);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 6);
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);

    printAlternate(head, true);

    return 0;
}
