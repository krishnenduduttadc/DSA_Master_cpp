#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int intersectPoint(Node* head1, Node* head2) {
    Node* p1 = head1;
    Node* p2 = head2;
    int s1 = 0, s2 = 0;

    while (p1 != nullptr) {
        s1++;
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        s2++;
        p2 = p2->next;
    }

    p1 = head1;
    p2 = head2;

    if (s1 > s2) {
        int diff = s1 - s2;
        while (diff-- > 0) p1 = p1->next;
    } else {
        int diff = s2 - s1;
        while (diff-- > 0) p2 = p2->next;
    }

    while (p1 != nullptr && p2 != nullptr && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    if (p1 == nullptr) return -1;

    return p1->data;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* common = new Node(8);
    common->next = new Node(10);

    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;

    Node* head2 = new Node(4);
    head2->next = new Node(7);
    head2->next->next = common;

    int result = intersectPoint(head1, head2);
    cout << "The intersection point data is: " << result << endl;

    delete common->next;
    delete common;
    delete head1->next->next;
    delete head1->next;
    delete head1;
    delete head2->next;
    delete head2;

    return 0;
}
