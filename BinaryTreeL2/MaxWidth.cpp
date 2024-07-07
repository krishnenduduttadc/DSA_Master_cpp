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

class MaxWidth {
public:
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

                // Count current level nodes
                ++currentWidth;

                // Enqueue left and right children if they exist
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // Update maxWidth if current level width is greater
            if (currentWidth > maxWidth) {
                maxWidth = currentWidth;
            }
        }

        return maxWidth;
    }
};

// Utility function to create a new node
TreeNode* newNode(int key) {
    TreeNode* node = new TreeNode(key);
    return node;
}

int main() {
    MaxWidth maxWidthCalculator;
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);

    int maxWidth = maxWidthCalculator.widthOfBinaryTree(root);

    // Print the maximum width of the binary tree
    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    // Clean up memory (optional in this example)
    // You may need to delete nodes if not using smart pointers
    return 0;
}
