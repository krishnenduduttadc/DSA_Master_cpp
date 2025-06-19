#include <iostream>
#include <climits>   // For INT_MIN
#include <algorithm> // For max
using namespace std;

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

int maxPathDown(TreeNode* node, int& maxValue) {
    if (node == nullptr) return 0;
    
    int left = max(0, maxPathDown(node->left, maxValue)); // Ignore negative sums
    int right = max(0, maxPathDown(node->right, maxValue)); // Ignore negative sums
    
    maxValue = max(maxValue, left + right + node->key);
    
    return max(left, right) + node->key;
}

int maxPathSum(TreeNode* root) {
    int maxValue = INT_MIN; // Initialize with minimum possible integer value
    maxPathDown(root, maxValue);
    return maxValue;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int answer = maxPathSum(root);
    cout << "The Max Path Sum for this tree is " << answer << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
