#include <iostream>
#include <queue> // for std::queue

// Node structure definition
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

// Function to check if the tree is symmetric
bool isSymmetricHelp(TreeNode* left, TreeNode* right);

bool isSymmetric(TreeNode* root) {
    return root == nullptr || isSymmetricHelp(root->left, root->right);
}

// Helper function to recursively check symmetry
bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
    if (left == nullptr || right == nullptr)
        return left == right;
    if (left->key != right->key)
        return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

// Function to create a new node
TreeNode* newNode(int key) {
    return new TreeNode(key);
}

int main() {
    // Constructing the tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);

    // Checking if the tree is symmetric
    bool isSym = isSymmetric(root);
    if (isSym)
        std::cout << "The tree is symmetric." << std::endl;
    else
        std::cout << "The tree is not symmetric." << std::endl;

    return 0;
}
