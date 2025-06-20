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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    ListNode *c1 = l1;
    ListNode *c2 = l2;

    while (c1 != nullptr && c2 != nullptr) {
        if (c1->val < c2->val) {
            prev->next = c1;
            c1 = c1->next;
        } else {
            prev->next = c2;
            c2 = c2->next;
        }
        prev = prev->next;
    }

    prev->next = (c1 != nullptr) ? c1 : c2;
    return dummy->next;
}

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);

    ListNode *mergedHead = mergeTwoLists(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    deleteList(mergedHead);

    return 0;
}
