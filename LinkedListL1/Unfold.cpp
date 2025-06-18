#include <iostream>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

// Function to reverse a linked list
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

// Function to unfold a folded linked list
void unfold(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* fh = head;           // first head
    Node* fp = fh;             // first pointer

    Node* sh = head->next;     // second head
    Node* sp = sh;             // second pointer

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

// Function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Hardcoded input: folded list like 1 -> 6 -> 2 -> 5 -> 3 -> 4
    Node* head = createNode(1);
    head->next = createNode(6);
    head->next->next = createNode(2);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(4);

    cout << "Original folded list:\n";
    printList(head);

    // Unfold the list
    unfold(head);

    cout << "Unfolded list:\n";
    printList(head);

    // Clean up memory
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
