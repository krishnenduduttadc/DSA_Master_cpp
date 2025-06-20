#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* concatenate(Node* H1, Node* H2) {
    if (H1 == nullptr) return H2;
    if (H2 == nullptr) return H1;

    Node* T1 = H1->left;
    Node* T2 = H2->left;

    T1->right = H2;
    H2->left = T1;

    T2->right = H1;
    H1->left = T2;

    return H1;
}

Node* bTreeToClist(Node* root) {
    if (root == nullptr) return nullptr;

    Node* l = bTreeToClist(root->left);
    Node* r = bTreeToClist(root->right);

    root->left = root->right = root;

    Node* result = concatenate(concatenate(l, root), r);

    return result;
}

void printCList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->right;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Creating a sample binary tree:
    //     1
    //    / \
    //   2   3
    //  / \   \
    // 4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Node* head = bTreeToClist(root);

    cout << "Circular Doubly Linked List:" << endl;
    printCList(head);

    return 0;
}
