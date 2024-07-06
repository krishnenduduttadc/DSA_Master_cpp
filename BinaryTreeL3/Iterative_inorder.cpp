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

// Function to perform iterative inorder traversal
std::vector<int> inOrderTrav(TreeNode* root) {
    std::vector<int> inOrder;
    std::stack<TreeNode*> s;
    TreeNode* curr = root;

    while (true) {
        if (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        } else {
            if (s.empty()) break;
            curr = s.top();
            inOrder.push_back(curr->key);
            s.pop();
            curr = curr->right;
        }
    }
    return inOrder;
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

    // Perform iterative inorder traversal
    std::vector<int> inOrder = inOrderTrav(root);

    // Print the result
    std::cout << "The inorder traversal is : ";
    for (int i = 0; i < inOrder.size(); i++) {
        std::cout << inOrder[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
