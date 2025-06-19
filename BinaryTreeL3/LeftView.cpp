#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
   TreeNode(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

void leftSideView(TreeNode* root, vector<int>& result, int currDepth) {
    if (root == nullptr) {
        return;
    }
    
    if (currDepth == result.size()) {
        result.push_back(root->key);
    }

    leftSideView(root->left, result, currDepth + 1);
    leftSideView(root->right, result, currDepth + 1);
}

vector<int> lightSideView(TreeNode* root) {
    vector<int> result;
    leftSideView(root, result, 0);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    // Finding the left view of the binary tree
    vector<int> res = lightSideView(root);

    // Output the left view elements
    cout << "The left view of the binary tree is: ";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
