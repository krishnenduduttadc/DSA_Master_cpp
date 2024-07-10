#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left = nullptr, Node* right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

// Function to display the binary tree (inorder traversal)
void display(Node* node) {
    if (node == nullptr) {
        return;
    }

    display(node->left);
    cout << node->data << " ";
    display(node->right);
}

// Function to print nodes that have exactly one child
void printSingleChildNodes(Node* node, Node* parent) {
    if (node == nullptr) {
        return;
    }

    // Check if node has exactly one child
    if ((parent != nullptr && parent->left == node && parent->right == nullptr) ||
        (parent != nullptr && parent->right == node && parent->left == nullptr)) {
        cout << node->data << " ";
    }

    printSingleChildNodes(node->left, node);
    printSingleChildNodes(node->right, node);
}

int main() {
    // Hardcoded tree construction
    Node* root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->left->right->left = new Node(30);
    root->right = new Node(75);
    root->right->left = new Node(62);
    root->right->left->right = new Node(70);
    root->right->right = new Node(87);

    cout << "Binary Tree:" << endl;
    display(root);
    cout << endl << "Single Child Nodes:" << endl;
    printSingleChildNodes(root, nullptr);

    // Clean up dynamically allocated memory
    delete root->right->left->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
