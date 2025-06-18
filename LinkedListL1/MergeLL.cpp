#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to add a node at the end of the list
void addLast(Node*& head, Node*& tail, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to merge two sorted linked lists
Node* sortedMerge(Node* headA, Node* headB) {
    Node* dummyNode = new Node(0);
    Node* tail = dummyNode;

    while (true) {
        if (headA == nullptr) {
            tail->next = headB;
            break;
        }
        if (headB == nullptr) {
            tail->next = headA;
            break;
        }

        if (headA->data <= headB->data) {
            tail->next = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            headB = headB->next;
        }
        tail = tail->next;
    }

    Node* mergedHead = dummyNode->next;
    delete dummyNode; // Free dummy node
    return mergedHead;
}

// Main function
int main() {
    // First linked list
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    addLast(head1, tail1, 5);
    addLast(head1, tail1, 10);
    addLast(head1, tail1, 15);

    // Second linked list
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    addLast(head2, tail2, 2);
    addLast(head2, tail2, 3);
    addLast(head2, tail2, 20);

    // Merge and display
    Node* mergedHead = sortedMerge(head1, head2);
    cout << "Merged Linked List:" << endl;
    display(mergedHead);

    // Optional: Free memory
    Node* temp;
    while (mergedHead != nullptr) {
        temp = mergedHead;
        mergedHead = mergedHead->next;
        delete temp;
    }

    return 0;
}
