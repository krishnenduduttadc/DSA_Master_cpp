#include <iostream>
#include <climits>   // For INT_MIN
#include <algorithm> // For std::max
using namespace std;
// TreeNode structure definition
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to calculate the maximum path sum going down from a node
int maxPathDown(TreeNode* node, int& maxValue) {
    if (node == nullptr) return 0;
    
    // Calculate maximum path sums from left and right subtrees
    int left = std::max(0, maxPathDown(node->left, maxValue)); // Ignore negative sums
    int right = std::max(0, maxPathDown(node->right, maxValue)); // Ignore negative sums
    
    // Update maxValue with the maximum path sum found so far
    maxValue = std::max(maxValue, left + right + node->key);
    
    // Return the maximum path sum going down from the current node
    return std::max(left, right) + node->key;
}

// Function to find the maximum path sum in a binary tree
int maxPathSum(TreeNode* root) {
    int maxValue = INT_MIN; // Initialize with minimum possible integer value
    maxPathDown(root, maxValue);
    return maxValue;
}

int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Finding the maximum path sum in the binary tree
    int answer = maxPathSum(root);
    std::cout << "The Max Path Sum for this tree is " << answer << std::endl;

    // Deallocating memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
