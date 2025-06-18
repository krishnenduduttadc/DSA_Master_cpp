#include <iostream>
using namespace std;

// Node structure for the linked list
struct ListNode {
    int val;
    ListNode* next;
};

// Function to create a new node
ListNode* createNode(int val) {
    ListNode* newNode = new ListNode;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

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
    // Create the sorted linked list: 6 -> 10 -> 11 -> 11
    ListNode* llist = createNode(6);
    llist->next = createNode(10);
    llist->next->next = createNode(11);
    llist->next->next->next = createNode(11);

    // Print the original list
    cout << "Original Linked List:" << endl;
    printList(llist);

    // Remove duplicates
    ListNode* ans = removeDuplicates(llist);

    // Print the updated list
    cout << "Linked List after removing duplicates:" << endl;
    printList(ans);

    // Cleanup memory
    while (ans != nullptr) {
        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
    }

    return 0;
}
