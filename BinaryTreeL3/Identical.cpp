#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createTreeNode(int x) {
    TreeNode* node = new TreeNode;
    node->val = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool isIdentical(TreeNode* node1, TreeNode* node2) {
    if (node1 == nullptr && node2 == nullptr)
        return true;
    else if (node1 == nullptr || node2 == nullptr)
        return false;

    return (node1->val == node2->val) &&
           isIdentical(node1->left, node2->left) &&
           isIdentical(node1->right, node2->right);
}

int main() {
    TreeNode* root1 = createTreeNode(1);
    root1->left = createTreeNode(2);
    root1->right = createTreeNode(3);
    root1->right->left = createTreeNode(4);
    root1->right->right = createTreeNode(5);

    TreeNode* root2 = createTreeNode(1);
    root2->left = createTreeNode(2);
    root2->right = createTreeNode(3);
    root2->right->left = createTreeNode(4);

    if (isIdentical(root1, root2))
        cout << "Two Trees are identical" << endl;
    else
        cout << "Two trees are non-identical" << endl;

    return 0;
}
