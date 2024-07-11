#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

Node* findCycleNode(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Detect cycle using Floyd's Cycle Detection Algorithm
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) break;
    }

    if (slow != fast) return nullptr;

    // Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a cycle by pointing the next of last node to the node with value 3 (index 2)
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    Node* cycleNode = head->next->next; // Node with value 3
    tail->next = cycleNode;

    // Find the start node of the cycle
    Node* ans = findCycleNode(head);
    cout << (ans != nullptr ? ans->val : -1) << endl;

    // Clean up memory
    // In a real-world scenario, you would implement a function to delete the linked list nodes.
    // For brevity, memory cleanup is not shown in this example.

    return 0;
}
