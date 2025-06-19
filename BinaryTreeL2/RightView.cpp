#include <iostream>
#include <vector>
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

vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (i == n - 1) {
                result.push_back(node->val);
            }

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    return result;
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

    vector<int> result = rightView(root);

    cout << "Right view of the binary tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
