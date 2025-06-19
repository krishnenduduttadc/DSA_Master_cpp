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

vector<vector<int>> leftview(TreeNode* root) {
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

            if (i == 0) {
                level.push_back(node->val);
            }

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        result.push_back(level); 
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

    vector<vector<int>> result = leftview(root);

    cout << "Left view of the binary tree:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    
    return 0;
}
