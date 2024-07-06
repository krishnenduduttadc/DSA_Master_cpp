#include <iostream>
#include <vector>
#include <stack>

// TreeNode structure definition
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

// Function to perform iterative preorder traversal
std::vector<int> preOrderTrav(TreeNode* root) {
    std::vector<int> preOrder;
    if (root == nullptr)
        return preOrder;

    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* topNode = s.top();
        preOrder.push_back(topNode->key);
        s.pop();
        if (topNode->right != nullptr)
            s.push(topNode->right);
        if (topNode->left != nullptr)
            s.push(topNode->left);
    }
    return preOrder;
}

int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    // Perform iterative preorder traversal
    std::vector<int> preOrder = preOrderTrav(root);

    // Print the result
    std::cout << "The preorder traversal is : ";
    for (int i = 0; i < preOrder.size(); i++) {
        std::cout << preOrder[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
