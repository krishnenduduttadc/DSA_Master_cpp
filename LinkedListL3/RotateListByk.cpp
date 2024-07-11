#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

class RotateListByk {
public:
    Node* rotateRight(Node* head, int k) {
        if (head == nullptr || k == 0) return head;

        int length = 1;
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        k = k % length;
        if (k == 0) return head;

        Node* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        Node* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
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
    RotateListByk solution;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* result = solution.rotateRight(head, 2);
    RotateListByk::printList(result);

    // Free the allocated memory
    Node* curr = result;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
