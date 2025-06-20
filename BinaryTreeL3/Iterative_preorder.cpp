#include <iostream>
#include <vector>
#include <stack>

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

vector<int> preOrderTrav(TreeNode* root) {
    vector<int> preOrder;
    if (root == nullptr)
        return preOrder;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* topNode = s.top();
        preOrder.push_back(topNode->key);
        s.pop();
        if (topNode->right != nullptr)
            s.push(topNode->right);
        if (topNode->left != nullptr)
            s.push(topNode->left);
    }
    return preOrder;
}

int main() {
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

    vector<int> preOrder = preOrderTrav(root);

    cout << "The preorder traversal is : ";
    for (int i = 0; i < preOrder.size(); i++) {
        cout << preOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
