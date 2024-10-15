#include <iostream>
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
    int count = 0;  // To keep track of how many nodes have been visited
    int result = -1;  // To store the k-th largest node value

    // Helper function for reverse in-order traversal (right-root-left)
    void reverseInOrder(Node* root, int k) {
        if (root == nullptr || count >= k) {
            return;
        }

        // Traverse the right subtree first (larger values)
        reverseInOrder(root->right, k);
        
        // Increment the count of visited nodes
        count++;

        // If count is equal to k, store the result
        if (count == k) {
            result = root->val;
            return; // Exit early since we found the k-th largest
        }

        // Traverse the left subtree
        reverseInOrder(root->left, k);
    }

    // Function to find the k-th largest node in a BST
    int kthLargestNode(Node* root, int k) {
        count = 0;    // Reset the count before each function call
        result = -1;  // Reset the result before each function call
        reverseInOrder(root, k);  // Start the reverse in-order traversal
        return result;  // Return the k-th largest value
    }
};

int main() {
    // Create a sample Binary Search Tree (BST)
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    // Solution instance
    Solution sol;

    // Find the k-th largest node
    int k = 3;
    int kthLargest = sol.kthLargestNode(root, k);
    
    if (kthLargest != -1) {
        cout << "The " << k << "-th largest node in the BST is: " << kthLargest << endl;
    } else {
        cout << "There are less than " << k << " nodes in the BST." << endl;
    }

    return 0;
}


/*
7 3
4 2 L
4 6 R
2 3 R
2 1 L
6 5 L
6 7 R

*/