#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class SplitLinkedListInParts {
public:
    std::vector<Node*> splitListToParts(Node* root, int k) {
        std::vector<Node*> parts(k, nullptr);
        int length = 0;
        Node* temp = root;

        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int n = length / k, r = length % k;
        Node* current = root;
        Node* prev = nullptr;

        for (int i = 0; i < k; i++) {
            parts[i] = current;
            for (int j = 0; j < n + (i < r ? 1 : 0); j++) {
                prev = current;
                if (current != nullptr) {
                    current = current->next;
                }
            }
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }

        return parts;
    }

    static void printList(Node* head) {
        while (head != nullptr) {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << "null" << std::endl;
    }
};

int main() {
    SplitLinkedListInParts solution;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    SplitLinkedListInParts::printList(head);
    std::vector<Node*> result = solution.splitListToParts(head, 3);
    for (Node* part : result) {
        SplitLinkedListInParts::printList(part);
    }

    // Free the allocated memory
    for (Node* part : result) {
        Node* curr = part;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    return 0;
}
