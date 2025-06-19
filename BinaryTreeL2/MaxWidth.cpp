#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int widthOfBinaryTree(TreeNode* root) {
    if (!root) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int n = q.size();
        int currentWidth = 0;

        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front();
            q.pop();

            ++currentWidth;

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        if (currentWidth > maxWidth) {
            maxWidth = currentWidth;
        }
    }

    return maxWidth;
}

TreeNode* newNode(int key) {
    TreeNode* node = new TreeNode(key);
    return node;
}

int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);

    int maxWidth = widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    return 0;
}
