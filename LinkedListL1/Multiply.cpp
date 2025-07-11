#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* addTwoLinkedList(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry > 0) {
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
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

Node* multiplyLLWithDigit(Node* head, int digit) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    Node* temp = head;
    int carry = 0;

    while (temp != nullptr || carry != 0) {
        int product = carry + (temp != nullptr ? temp->val * digit : 0);
        carry = product / 10;
        curr->next = new Node(product % 10);
        curr = curr->next;

        if (temp != nullptr) temp = temp->next;
    }

    return dummy->next;
}

Node* multiplyTwoLL(Node* l1, Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    Node* result = nullptr;
    Node* l2_curr = l2;
    int shift = 0;

    while (l2_curr != nullptr) {
        Node* partial = multiplyLLWithDigit(l1, l2_curr->val);

        for (int i = 0; i < shift; i++) {
            Node* zero = new Node(0);
            zero->next = partial;
            partial = zero;
        }

        result = addTwoLinkedList(result, partial);
        l2_curr = l2_curr->next;
        shift++;
    }

    return reverse(result);
}

Node* createList(int arr[], int n) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    for (int i = 0; i < n; ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {3, 4, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node* l1 = createList(arr1, n1);

    int arr2[] = {4, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node* l2 = createList(arr2, n2);

    Node* result = multiplyTwoLL(l1, l2);

    printList(result);

    return 0;
}
