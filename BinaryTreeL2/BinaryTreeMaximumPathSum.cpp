#include <iostream>
#include <algorithm>
#include <climits> // For INT_MIN

using namespace std;

// Definition of a Node in the Binary Tree
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to compute the maximum path sum in a binary tree
int maxPathSumUtil(Node* node, int& maxSum) {
    if (node == nullptr) return 0;

    // Get maximum sum from left and right subtrees (ignore negative sums)
    int left = max(maxPathSumUtil(node->left, maxSum), 0);
    int right = max(maxPathSumUtil(node->right, maxSum), 0);

    // Compute the maximum sum with the current node as the root
    int localMax = node->val + left + right;

    // Update the global maximum path sum
    maxSum = max(maxSum, localMax);

    // Return the maximum single path sum (either left or right)
    return node->val + max(left, right);
}

// Wrapper function to find the maximum path sum
int maxPathSum(Node* root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

int main() {
    // Constructing the example binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Calculating and printing the maximum path sum
    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;  // Output: 16

    return 0;
}
