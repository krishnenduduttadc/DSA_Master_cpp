#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int node_value) {
        val = node_value;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to find the maximum node in a BST
    int maxNodeInBST(Node* root) {
        if (root == nullptr) {
            return INT_MIN; // Handle the case where the tree is empty
        }

        // Traverse to the rightmost node
        while (root->right != nullptr) {
            root = root->right;
        }

        // Return the value of the rightmost node (which is the max in a BST)
        return root->val;
    }
};

int main() {
    // Create a sample Binary Search Tree (BST)
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(35);
    root->right->left = new Node(25);

    // Solution instance
    Solution sol;

    // Call the maxNodeInBST function and display the result
    cout << "The maximum node in the BST is: " << sol.maxNodeInBST(root) << endl;

    return 0;
}
