#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
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
Node* addTwoLinkedList(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* p = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        p->next = new Node(sum % 10);
        p = p->next;
    }

    return dummy->next;
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
        ac = ac->next;

        if (curr != nullptr) curr = curr->next;
    }

    return dummy->next;
}

// Function to multiply two linked lists representing numbers
Node* multiplyTwoLL(Node* l1, Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    Node* result = nullptr;
    Node* l2_itr = l2;
    int shift = 0;

    // Multiply l1 with each digit of l2
    while (l2_itr != nullptr) {
        Node* prod = multiplyLLWithDigit(l1, l2_itr->val);

        // Add the current product with proper shifting
        Node* temp = prod;
        for (int i = 0; i < shift; ++i) {
            Node* zeroNode = new Node(0);
            zeroNode->next = temp;
            temp = zeroNode;
        }

        result = addTwoLinkedList(result, temp);
        l2_itr = l2_itr->next;
        ++shift;
    }

    return reverse(result);
}

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->val;
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
