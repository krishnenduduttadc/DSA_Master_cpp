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
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

Node* add(Node* l1, Node* l2, int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
        return nullptr;
    }

    int value = carry;
    if (l1 != nullptr) value += l1->data;
    if (l2 != nullptr) value += l2->data;

    Node* result = createNode(value % 10);

    Node* next1 = (l1 != nullptr) ? l1->next : nullptr;
    Node* next2 = (l2 != nullptr) ? l2->next : nullptr;
    result->next = add(next1, next2, value / 10);

    return result;
}

int main() {
    Node* head1 = createNode(7);
    head1->next = createNode(1);
    head1->next->next = createNode(6);

    Node* head2 = createNode(5);
    head2->next = createNode(9);
    head2->next->next = createNode(2);

    Node* result = add(head1, head2, 0);

    cout << "Result of addition:" << endl;
    printList(result);

    return 0;
}
