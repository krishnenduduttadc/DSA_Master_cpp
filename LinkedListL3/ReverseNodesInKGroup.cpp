#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class ReverseNodesInKGroup {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        Node dummy(0);
        dummy.next = head;
        Node* curr = &dummy;
        Node* next = &dummy;
        Node* pre = &dummy;
        int count = 0;

        // Count the total number of nodes
        while (curr->next != nullptr) {
            curr = curr->next;
            count++;
        }

        while (count >= k) {
            curr = pre->next;
            next = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            pre = curr;
            count -= k;
        }

        return dummy.next;
    }

    static void printList(Node* head) {
        while (head != nullptr) {
            std::cout << head->val << "->";
            head = head->next;
        }
        std::cout << "null" << std::endl;
    }

    static int len(Node* head) {
        int c = 0;
        while (head != nullptr) {
            head = head->next;
            c++;
        }
        return c;
    }
};

int main() {
    ReverseNodesInKGroup solution;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    ReverseNodesInKGroup::printList(head);
    Node* result = solution.reverseKGroup(head, 2);
    ReverseNodesInKGroup::printList(result);

    // Free the allocated memory
    Node* curr = result;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}