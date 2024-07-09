#include <iostream>
#include <unordered_map>

// Definition for a Node.
struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class CopyListWithRandomPointer {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> map;
        Node* curr = head;

        // First pass: create all nodes and store them in the map.
        while (curr != nullptr) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: assign next and random pointers.
        curr = head;
        while (curr != nullptr) {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }

    static void printList(Node* head) {
        while (head != nullptr) {
            std::cout << "Node(" << head->val << ")";
            if (head->random != nullptr) {
                std::cout << " [Random(" << head->random->val << ")]";
            }
            std::cout << " -> ";
            head = head->next;
        }
        std::cout << "null" << std::endl;
    }
};

int main() {
    CopyListWithRandomPointer solution;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;

    Node* result = solution.copyRandomList(head);
    CopyListWithRandomPointer::printList(result);

    // Free the allocated memory
    Node* curr = result;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
