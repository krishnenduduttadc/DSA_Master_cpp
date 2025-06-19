#include <iostream>
#include <cmath> // For pow function
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

int getHeight(TreeNode* node, bool isLeft) {
    int height = 0;
    while (node != nullptr) {
        height++;
        node = isLeft ? node->left : node->right;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftHeight = getHeight(root, true);
    int rightHeight = getHeight(root, false);

    if (leftHeight == rightHeight) {
        return pow(2, leftHeight) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Number of nodes: " << countNodes(root) << endl;  // Output: 6

    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
