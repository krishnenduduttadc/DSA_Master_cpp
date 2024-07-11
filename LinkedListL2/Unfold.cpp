#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* prev = nullptr;
    Node* curr = head;
    Node* forw = nullptr;

    while (curr != nullptr) {
        forw = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forw;
    }

    return prev;
}

void unfold(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* fh = head;
    Node* fp = fh;

    Node* sh = head->next;
    Node* sp = sh;

    while (sp != nullptr && sp->next != nullptr) {
        Node* f = sp->next;

        fp->next = f;
        sp->next = f->next;

        fp = fp->next;
        sp = sp->next;
    }

    fp->next = nullptr;

    sh = reverse(sh);
    fp->next = sh;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Hardcoding the linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Unfolding the list
    unfold(head);

    // Printing the unfolded list
    printList(head);

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
