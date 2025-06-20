#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

Node* swapPairs(Node* head) {
    Node dummy(0);
    dummy.next = head;
    Node* current = &dummy;

    while (current->next != nullptr && current->next->next != nullptr) {
        Node* first = current->next;
        Node* second = current->next->next;

        first->next = second->next;
        second->next = first;
        current->next = second;

        current = first;
    }

    return dummy.next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node* result = swapPairs(head);
    printList(result);

    // Free the allocated memory
    Node* curr = result;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
