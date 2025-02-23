#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data; // Correctly assigning data
        left = nullptr;
        right = nullptr;
    }
};

// Function to display the binary tree (preorder traversal)
void display(Node *node) {
    if (node == nullptr) {
        return;
    }

    string str = "";
    str += (node->left == nullptr ? "." : to_string(node->left->data)) + " <- " + to_string(node->data) + " -> ";
    str += (node->right == nullptr ? "." : to_string(node->right->data));
    cout << str << endl;

    display(node->left);
    display(node->right);
}

// Function to check if a subtree rooted at 'node' is a BST
bool isBST(Node *node, int minVal, int maxVal) {
    if (node == nullptr) {
        return true;
    }
    
    if (node->data <= minVal || node->data >= maxVal) {
        return false;
    }

    return isBST(node->left, minVal, node->data) && isBST(node->right, node->data, maxVal);
}

int main() {
    // Hardcoded tree construction
    Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->right->left = new Node(62);
    root->right->right = new Node(87);

    // Display tree structure
    cout << "Tree structure:" << endl;
    display(root);

    // Check if the tree is a BST
    bool result = isBST(root, INT_MIN, INT_MAX);
    cout << "\nIs the tree a BST? " << (result ? "Yes" : "No") << endl;

    return 0;
}
