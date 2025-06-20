#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = nullptr;
    }
};

Node* findCycleNode(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) break;
    }

    if (slow != fast) return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    Node* cycleNode = head->next->next; // Node with value 3
    tail->next = cycleNode;

    Node* ans = findCycleNode(head);
    cout << (ans != nullptr ? ans->val : -1) << endl;

    return 0;
}
