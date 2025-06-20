#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* createNode(int val) {
    ListNode* newNode = new ListNode;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* removeDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* curr = head;
    ListNode* th = nullptr;
    ListNode* tt = nullptr;

    while (curr != nullptr) {
        ListNode* forw = curr->next;
        curr->next = nullptr;

        if (tt == nullptr || tt->val != curr->val) {
            if (th == nullptr) {
                th = tt = curr;
            } else {
                tt->next = curr;
                tt = curr;
            }
        }
        curr = forw;
    }

    return th;
}

int main() {
    ListNode* llist = createNode(6);
    llist->next = createNode(10);
    llist->next->next = createNode(11);
    llist->next->next->next = createNode(11);

    cout << "Original Linked List:" << endl;
    printList(llist);

    ListNode* ans = removeDuplicates(llist);

    cout << "Linked List after removing duplicates:" << endl;
    printList(ans);

    while (ans != nullptr) {
        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
    }

    return 0;
}
