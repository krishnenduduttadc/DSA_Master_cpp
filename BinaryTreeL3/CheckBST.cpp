#include <iostream>
#include <climits>
using namespace std;

// Node structure for the binary tree
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

// Function to check if the binary tree is a valid BST
bool isValidBSTHelper(Node* node, long min, long max) {
    if (node == nullptr) return true;

    // Check if the current node's key is within the valid range
    if (node->key <= min || node->key >= max)
        return false;

    // Recursively check the left and right subtrees
    return isValidBSTHelper(node->left, min, node->key) &&
           isValidBSTHelper(node->right, node->key, max);
}

bool isValidBST(Node* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = nullptr;

    // Create a binary search tree
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // Check if the tree is a valid BST
    bool validBST = isValidBST(root);
    cout << "Is the tree a valid BST? " << (validBST ? "Yes" : "No") << endl;

    return 0;
}
