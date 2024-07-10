#include <iostream>
#include <vector>

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

// Function to find the left view of a binary tree
void leftSideView(TreeNode* root, std::vector<int>& result, int currDepth) {
    if (root == nullptr) {
        return;
    }
    
    // If the current depth equals the size of result, it's the first node we encounter at this depth
    if (currDepth == result.size()) {
        result.push_back(root->key);
    }

    // Recursively traverse left and right subtrees, incrementing depth
    leftSideView(root->left, result, currDepth + 1);
    leftSideView(root->right, result, currDepth + 1);
}

// Function to initiate left view traversal
std::vector<int> lightSideView(TreeNode* root) {
    std::vector<int> result;
    leftSideView(root, result, 0);
    return result;
}

int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    // Finding the left view of the binary tree
    std::vector<int> res = lightSideView(root);

    // Output the left view elements
    std::cout << "The left view of the binary tree is: ";
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
