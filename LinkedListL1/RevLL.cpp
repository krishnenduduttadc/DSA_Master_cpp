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

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

Node* reverseRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);

    cout << "Original List: ";
    display(head);

    head = reverseRecursive(head);
    cout << "List after recursive reversal: ";
    display(head);

    head = reverseIterative(head);
    cout << "List after iterative reversal: ";
    display(head);

    deleteList(head);

    return 0;
}
