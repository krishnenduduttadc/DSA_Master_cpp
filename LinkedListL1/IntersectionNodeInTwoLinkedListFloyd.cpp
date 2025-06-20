#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

void printList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        cout << current->val;
        current = current->next;
        if (current != nullptr) cout << " -> ";
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    ListNode *current = head;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
