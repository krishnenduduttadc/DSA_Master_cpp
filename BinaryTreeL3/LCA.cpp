#include <iostream>
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: if root is null or root is one of p or q, return root
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    
    // Recursively search left and right subtrees
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // Result conditions
    if (left == nullptr) {
        return right;
    } else if (right == nullptr) {
        return left;
    } else {
        return root;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    TreeNode* lca = lowestCommonAncestor(root, root->left->right, root->left->left->left);

    cout << "Lowest Common Ancestor (LCA) key: " << lca->key << endl;

    return 0;
}
