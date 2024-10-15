#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val; 
    Node *left;
    Node *right;

    Node(int node_value) {
        val = node_value;
        left = right = nullptr;
    }
};

class Solution {
public:
    Node* lcaInBST(Node* root, int p, int q) {
        if (root == nullptr) {
            return nullptr; // Base case: if the tree is empty
        }

        // If both p and q are smaller than root, LCA must be in the left subtree
        if (p < root->val && q < root->val) {
            return lcaInBST(root->left, p, q);
        }

        // If both p and q are greater than root, LCA must be in the right subtree
        if (p > root->val && q > root->val) {
            return lcaInBST(root->right, p, q);
        }

        // We have found the split point, i.e., one of p or q is on one side and the other is on the other side
        return root; // This is the LCA
    }
};

// Function to insert a new value in the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to display the BST (in-order traversal)
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    cout << "In-order traversal of the BST: ";
    inorderTraversal(root); // Display the BST
    cout << endl;

    Solution sol;
    
    // Test cases for LCA
    int p = 5, q = 15;
    Node* lca = sol.lcaInBST(root, p, q);
    if (lca != nullptr) {
        cout << "LCA of " << p << " and " << q << " is: " << lca->val << endl; // Expected LCA: 10
    } else {
        cout << "LCA not found." << endl;
    }

    p = 5, q = 25;
    lca = sol.lcaInBST(root, p, q);
    if (lca != nullptr) {
        cout << "LCA of " << p << " and " << q << " is: " << lca->val << endl; // Expected LCA: 20
    } else {
        cout << "LCA not found." << endl;
    }

    p = 15, q = 35;
    lca = sol.lcaInBST(root, p, q);
    if (lca != nullptr) {
        cout << "LCA of " << p << " and " << q << " is: " << lca->val << endl; // Expected LCA: 20
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}
