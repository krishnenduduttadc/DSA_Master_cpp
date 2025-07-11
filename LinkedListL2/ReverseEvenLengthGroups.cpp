#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

Node* reverse(Node* head, int k) {
    Node* prev = nullptr;
    while (k > 0) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        k--;
    }
    return prev;
}

Node* reverseEvenLengthGroups(Node* head) {
    Node dummy(0);
    dummy.next = head;
    Node* groupPrev = &dummy;
    int groupSize = 1;

    while (head != nullptr) {
        int count = 0;
        Node* groupHead = head;

        while (count < groupSize && head != nullptr) {
            head = head->next;
            count++;
        }

        if (count % 2 == 0) {
            Node* reversedHead = reverse(groupHead, count);
            groupPrev->next = reversedHead;
            groupHead->next = head;
            groupPrev = groupHead;
        } else {
            groupPrev = groupHead;
        }

        groupSize++;
    }

    return dummy.next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    Node* result = reverseEvenLengthGroups(head);
    printList(result);

    // Free the allocated memory
    Node* curr = result;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
