#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void flatten(Node* root, Node*& prev) {
    if (root == nullptr) return;

    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = nullptr;
    prev = root;
}

void printList(Node* root) {
    while (root->right != nullptr) {
        cout << root->key << "->";
        root = root->right;
    }
    cout << root->key;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right = createNode(5);
    root->right->right = createNode(6);
    root->right->right->left = createNode(7);

    Node* prev = nullptr;
    flatten(root, prev);
    printList(root);

    // Clean up allocated memory
    while (root != nullptr) {
        Node* temp = root;
        root = root->right;
        delete temp;
    }

    return 0;
}
