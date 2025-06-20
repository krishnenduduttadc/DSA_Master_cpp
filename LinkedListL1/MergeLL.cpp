#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void addLast(Node*& head, Node*& tail, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

int main() {
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    addLast(head1, tail1, 5);
    addLast(head1, tail1, 10);
    addLast(head1, tail1, 15);

    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    addLast(head2, tail2, 2);
    addLast(head2, tail2, 3);
    addLast(head2, tail2, 20);

    Node* mergedHead = sortedMerge(head1, head2);
    cout << "Merged Linked List:" << endl;
    display(mergedHead);

    Node* temp;
    while (mergedHead != nullptr) {
        temp = mergedHead;
        mergedHead = mergedHead->next;
        delete temp;
    }

    return 0;
}
