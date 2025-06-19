#include <iostream>
#include <queue> // for queue
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

bool isSymmetricHelp(TreeNode* left, TreeNode* right);

bool isSymmetric(TreeNode* root) {
    return root == nullptr || isSymmetricHelp(root->left, root->right);
}

bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
    if (left == nullptr || right == nullptr)
        return left == right;
    if (left->key != right->key)
        return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

TreeNode* newNode(int key) {
    return new TreeNode(key);
}

int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);

    bool isSym = isSymmetric(root);
    if (isSym)
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}
