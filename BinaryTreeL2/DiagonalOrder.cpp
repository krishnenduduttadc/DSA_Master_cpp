#include <iostream>
#include <vector>
#include <queue>

// TreeNode structure definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform diagonal order traversal of a binary tree
std::vector<std::vector<int>> diagonalOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if (root == nullptr) return ans;

    std::queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        std::vector<int> smallAns;

        while (size--) {
            TreeNode* node = que.front();
            que.pop();

            while (node != nullptr) {
                smallAns.push_back(node->val);

                if (node->left) que.push(node->left);

                node = node->right;
            }
        }

        ans.push_back(smallAns);
    }

    return ans;
}

int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Calling diagonalOrder function and printing the result
    std::vector<std::vector<int>> ans = diagonalOrder(root);

    std::cout << "Diagonal Order Traversal:\n";
    for (const auto& level : ans) {
        for (int num : level) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    // Deallocating memory to avoid memory leaks
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
