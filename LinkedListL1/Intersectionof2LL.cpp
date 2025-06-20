#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

int getCount(Node* node) {
    int count = 0;
    Node* current = node;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int getIntersectionNode(int d, Node* node1, Node* node2) {
    Node* current1 = node1;
    Node* current2 = node2;

    for (int i = 0; i < d; i++) {
        if (current1 == nullptr) return -1;
        current1 = current1->next;
    }

    while (current1 != nullptr && current2 != nullptr) {
        if (current1 == current2) return current1->data;
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}

int getNode(Node* head1, Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);

    if (c1 > c2) {
        return getIntersectionNode(c1 - c2, head1, head2);
    } else {
        return getIntersectionNode(c2 - c1, head2, head1);
    }
}

int main() {
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    Node* intersection = new Node(15);
    head1->next->next->next = intersection;
    intersection->next = new Node(30);

    Node* head2 = new Node(10);
    head2->next = intersection;

    cout << "The node of intersection is " << getNode(head1, head2) << endl;

    delete intersection->next;
    delete intersection;
    delete head1->next->next;
    delete head1->next;
    delete head1;
    delete head2;

    return 0;
}
