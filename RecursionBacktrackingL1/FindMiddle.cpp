#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int n;
Node* mid;

Node* newLNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void midpoint_util(Node* head) {
    if (head == nullptr) {
        n = n / 2;
        return;
    }
    n = n + 1;
    midpoint_util(head->next);
    n = n - 1;
    if (n == 0) {
        mid = head;
    }
}

Node* midpoint(Node* head) {
    mid = nullptr;
    n = 1;
    midpoint_util(head);
    return mid;
}

int main() {
    Node* head = newLNode(1);
    head->next = newLNode(2);
    head->next->next = newLNode(3);
    head->next->next->next = newLNode(4);
    head->next->next->next->next = newLNode(5);
    Node* result = midpoint(head);
    cout << result->data << endl;
    return 0;
}
