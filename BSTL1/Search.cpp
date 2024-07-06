#include <iostream>
using namespace std;

// Define Node structure for BST
struct Node {
    int key;
    Node *left, *right;
    
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to search for a node in BST
bool searchInBST(Node* root, int k) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == k) {
        return true;
    }
    if (k < root->key) {
        return searchInBST(root->left, k);
    }
    if (k > root->key) {
        return searchInBST(root->right, k);
    }
    return false;
}

int main() {
    // Create the BST
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    // Search for nodes from 0 to 9
    for (int i = 0; i < 10; i++) {
        cout << i << " is Present? " << (searchInBST(root, i) ? "Yes" : "No") << endl;
    }

    return 0;
}
