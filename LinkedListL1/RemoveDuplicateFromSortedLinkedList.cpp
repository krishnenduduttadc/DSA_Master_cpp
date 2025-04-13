#include <iostream>
using namespace std;

// Node class for the linked list
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to remove duplicates from a sorted linked list
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
    // Creating a linked list with 4 hard-coded nodes
    ListNode* head = nullptr;
    ListNode* llist = new ListNode(6);
    llist->next = new ListNode(11);
    llist->next->next = new ListNode(10);
    llist->next->next->next = new ListNode(11);

    // Print the original linked list
    cout << "Original Linked List:" << endl;
    printList(llist);

    // Remove duplicates
    ListNode* ans = removeDuplicates(llist);

    // Print the linked list after removing duplicates
    cout << "Linked List after removing duplicates:" << endl;
    printList(ans);

    return 0;
}
