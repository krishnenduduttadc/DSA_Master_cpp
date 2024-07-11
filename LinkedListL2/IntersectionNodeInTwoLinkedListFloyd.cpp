#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to print the linked list from a given head node
void printList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        cout << current->val;
        current = current->next;
        if (current != nullptr) cout << " -> ";
    }
    cout << endl;
}

// Main function to test the linked list operations
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Printing the linked list
    printList(head);

    // Clean up allocated memory (optional in this example)
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
