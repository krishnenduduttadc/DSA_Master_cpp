#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int val;
    Node* next;
    
    Node(int val) : val(val), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    
    return prev;
}

// Function to add two linked lists in place
void addTwoLinkedList(Node* head, Node* ansItr) {
    Node* c1 = head;
    Node* c2 = ansItr;
    
    int carry = 0;
    while (c1 != nullptr || carry != 0) {
        int sum = carry + (c1 != nullptr ? c1->val : 0) + (c2->next != nullptr ? c2->next->val : 0);
        int digit = sum % 10;
        carry = sum / 10;
        
        if (c2->next != nullptr) c2->next->val = digit;
        else c2->next = new Node(digit);
        
        if (c1 != nullptr) c1 = c1->next;
        c2 = c2->next;
    }
}

// Function to multiply a linked list with a single digit
Node* multiplyLLWithDigit(Node* head, int dig) {
    Node* dummy = new Node(-1);
    Node* ac = dummy;
    Node* curr = head;
    int carry = 0;
    while (curr != nullptr || carry != 0) {
        int sum = carry + (curr != nullptr ? curr->val * dig : 0);
        
        int digit = sum % 10;
        carry = sum / 10;
        
        ac->next = new Node(digit);
        
        if (curr != nullptr) curr = curr->next;
        ac = ac->next;
    }
    
    return dummy->next;
}

// Function to multiply two linked lists representing numbers
Node* multiplyTwoLL(Node* l1, Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    Node* l2_Itr = l2;
    Node* dummy = new Node(-1);
    Node* ansItr = dummy;
    
    while (l2_Itr != nullptr) {
        Node* prod = multiplyLLWithDigit(l1, l2_Itr->val);
        l2_Itr = l2_Itr->next;
        
        addTwoLinkedList(prod, ansItr);
        ansItr = ansItr->next;
    }
    
    return reverse(dummy->next);
}

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to create a linked list from an array of integers
Node* createList(int values[], int n) {
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    for (int i = 0; i < n; ++i) {
        prev->next = new Node(values[i]);
        prev = prev->next;
    }
    return dummy->next;
}

int main() {
    // Hardcoding the lists
    // First list: 3 -> 4 -> 2 (represents the number 243)
    int arr1[] = {3, 4, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node* head1 = createList(arr1, n1);
    
    // Second list: 4 -> 6 -> 5 (represents the number 564)
    int arr2[] = {4, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node* head2 = createList(arr2, n2);
    
    // Multiplying the two linked lists
    Node* ans = multiplyTwoLL(head1, head2);
    
    // Printing the result
    printList(ans);
    
    return 0;
}
