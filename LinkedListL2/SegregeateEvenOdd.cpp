#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

Node* segregateEvenOdd(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* dummyEven = new Node(-1);
    Node* dummyOdd = new Node(-1);
    Node* evenTail = dummyEven;
    Node* oddTail = dummyOdd;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->val % 2 != 0) {
            oddTail->next = curr;
            oddTail = oddTail->next;
        } else {
            evenTail->next = curr;
            evenTail = evenTail->next;
        }

        curr = curr->next;
    }

    evenTail->next = dummyOdd->next;
    oddTail->next = nullptr;

    Node* result = dummyEven->next;
    delete dummyEven;
    delete dummyOdd;
    return result;
}

void push(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = head;
    head = new_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    push(head, 11);
    push(head, 10);
    push(head, 9);
    push(head, 6);

    Node* head1 = segregateEvenOdd(head);
    printList(head1);

    return 0;
}
