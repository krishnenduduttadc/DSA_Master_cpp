#include <iostream>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
};

// Create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

// Find middle of the linked list
Node* midNode(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Reverse linked list
Node* reverseOfLL(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* forw;

    while (curr != nullptr) {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
}

// Check if linked list is palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;

    Node* mid = midNode(head);

    Node* nHead = mid->next;
    mid->next = nullptr;
    nHead = reverseOfLL(nHead);

    Node* c1 = head;
    Node* c2 = nHead;
    bool res = true;

    while (c2 != nullptr) {
        if (c1->val != c2->val) {
            res = false;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }

    // Restore the list
    nHead = reverseOfLL(nHead);
    mid->next = nHead;

    return res;
}

// Create list from array
Node* createList(int values[], int n) {
    Node dummy;
    dummy.next = nullptr;
    Node* prev = &dummy;

    for (int i = 0; i < n; ++i) {
        prev->next = createNode(values[i]);
        prev = prev->next;
    }

    return dummy.next;
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = createList(arr, n);

    cout << boolalpha << isPalindrome(head) << endl;  // should print true

    return 0;
}
