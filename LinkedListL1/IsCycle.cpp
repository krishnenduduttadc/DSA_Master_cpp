#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
     Node(int x) {
        val = x;        // Assigns the parameter x to the member variable val
        next = nullptr; // Initializes the next pointer to nullptr
    }
};

bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
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

    cout << (hasCycle(head) ? "Cycle is present" : "No cycle") << endl;

    return 0;
}
