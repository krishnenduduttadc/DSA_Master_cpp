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

    // Hardcoded nodes to insert into the BST
    int nodes[] = {20, 10, 30, 5, 15, 25, 35};
    for (int val : nodes) {
        root = insert(root, val);
    }

    cout << "In-order traversal of the BST: ";
    inorderTraversal(root); // Display the BST
    cout << endl;

    Solution sol;
    
    // Hardcoded test cases for LCA
    int testCases[][2] = {{5, 15}, {5, 25}, {15, 35}};
    
    for (const auto& test : testCases) {
        int p = test[0], q = test[1];
        Node* lca = sol.lcaInBST(root, p, q);
        if (lca != nullptr) {
            cout << "LCA of " << p << " and " << q << " is: " << lca->val << endl; // Expected results
        } else {
            cout << "LCA not found." << endl;
        }
    }

    return 0;
}
