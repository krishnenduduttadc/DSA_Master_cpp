#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int x) {
        val = x;
        next = nullptr;
        random = nullptr;
    }
};

// Function to copy the linked list with random pointers
Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;

    unordered_map<Node*, Node*> map;

    // First pass: create new nodes and map original to new
    Node* curr = head;
    while (curr != nullptr) {
        map[curr] = new Node(curr->val);
        curr = curr->next;
    }

    // Second pass: set next and random pointers
    curr = head;
    while (curr != nullptr) {
        map[curr]->next = map[curr->next];
        map[curr]->random = map[curr->random];
        curr = curr->next;
    }

    return map[head];
}

// Helper function to print list with random pointers
void printListWithRandom(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << "(" << (curr->random ? to_string(curr->random->val) : "null") << ") ";
        curr = curr->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Assign random pointers
    head->random = head->next->next;       // 1 -> 3
    head->next->random = head;             // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    // Clone the list
    Node* clonedHead = copyRandomList(head);

    // Print both lists
    cout << "Original List:" << endl;
    printListWithRandom(head);
    cout << "\nCloned List:" << endl;
    printListWithRandom(clonedHead);

    return 0;
}
