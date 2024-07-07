#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class MaxDepth {
public:
    int levelOrder(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int n = q.size();
            depth++; // Increment depth for each level

            for (int i = 0; i < n; ++i) {
                TreeNode* f = q.front();
                q.pop();

                if (f->left) {
                    q.push(f->left);
                }
                if (f->right) {
                    q.push(f->right);
                }
            }
        }

        return depth;
    }
};

// Utility function to create a new node
TreeNode* newNode(int key) {
    TreeNode* node = new TreeNode(key);
    return node;
}

int main() {
    MaxDepth tree;
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int depth = tree.levelOrder(root);

    // Print the maximum depth of the binary tree
    cout << "Maximum depth of the binary tree: " << depth << endl;

    // Clean up memory (optional in this example)
    // You may need to delete nodes if not using smart pointers
    return 0;
}
