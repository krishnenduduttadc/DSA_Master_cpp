#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

class CloneLinkedList {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> map;

        // First pass: create new nodes and map original nodes to new nodes
        Node* curr = head;
        while (curr != nullptr) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: assign next and random pointers for new nodes
        curr = head;
        while (curr != nullptr) {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }

    // Helper method to print the linked list with random pointers
    void printListWithRandom(Node* head) {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->val << "(" << (curr->random != nullptr ? to_string(curr->random->val) : "null") << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    // Call the function to clone the linked list
    CloneLinkedList solution;
    Node* clonedHead = solution.copyRandomList(head);

    // Print the cloned linked list with random pointers
    cout << "Original List:" << endl;
    solution.printListWithRandom(head);
    cout << "\nCloned List:" << endl;
    solution.printListWithRandom(clonedHead);

    // Clean up memory
    // In a real-world scenario, you would implement a function to delete the linked list nodes.
    // For brevity, memory cleanup is not shown in this example.

    return 0;
}
