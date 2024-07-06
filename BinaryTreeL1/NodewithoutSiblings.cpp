#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to print nodes without siblings in a binary tree
void printNodesWithoutSibling(Node* root) {
    if (root == nullptr)
        return;

    // If the current node has exactly one child
    if ((root->left == nullptr && root->right != nullptr) || 
        (root->left != nullptr && root->right == nullptr)) {
        cout << root->data << " ";
    }

    // Recursively check left and right subtrees
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

int main() {
    // Hardcoded tree construction
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    // Print nodes without siblings
    cout << "Nodes without siblings: ";
    printNodesWithoutSibling(root);
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
