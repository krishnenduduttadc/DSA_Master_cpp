#include <iostream>
using namespace std;

// Definition of a ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Dummy node to simplify the merging logic
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    // Pointers to traverse both lists
    ListNode *c1 = l1;
    ListNode *c2 = l2;

    // Compare values and append nodes accordingly
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

    // Attach remaining nodes
    prev->next = (c1 != nullptr) ? c1 : c2;

    // Return the merged list (excluding the dummy node)
    return dummy->next;
}

// Function to print a linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to deallocate memory allocated for the linked list
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    // Creating two linked lists
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);

    // Merging the lists
    ListNode *mergedHead = mergeTwoLists(head1, head2);

    // Printing the merged list
    cout << "Merged List: ";
    printList(mergedHead);

    // Clean up memory
    deleteList(mergedHead);

    return 0;
}
