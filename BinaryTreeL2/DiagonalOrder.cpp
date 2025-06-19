#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

vector<vector<int>> diagonalOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        vector<int> smallAns;

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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = diagonalOrder(root);

    cout << "Diagonal Order Traversal:\n";
    for (const auto level : ans) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << "\n";
    }

    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
