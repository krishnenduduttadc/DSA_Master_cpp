#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class RightView {
public:
    vector<vector<int>> rightview(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Capture the last node value in each level (rightmost node)
                if (i == n - 1) {
                    level.push_back(node->val);
                }

                // Enqueue left and right children if they exist
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            result.push_back(level); // Add current level's rightmost node(s) to result
        }

        return result;
    }
};

// Utility function to create a new node
TreeNode* newNode(int key) {
    TreeNode* node = new TreeNode(key);
    return node;
}

int main() {
    RightView tree;
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<vector<int>> result = tree.rightview(root);

    // Print the right view of the binary tree
    cout << "Right view of the binary tree:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory (optional in this example)
    // You may need to delete nodes if not using smart pointers
    return 0;
}
