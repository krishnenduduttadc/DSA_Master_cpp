#include <iostream>
#include <algorithm> // for max function

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

int cameras = 0;

int minCamerasInBT(TreeNode* root) {
    if (root == nullptr) return 1; // No need for camera

    int lchild = minCamerasInBT(root->left);
    int rchild = minCamerasInBT(root->right);

    if (lchild == -1 || rchild == -1) {
        cameras++;
        return 0; // Place camera here
    }

    if (lchild == 0 || rchild == 0) return 1; // Covered by camera

    return -1; // Not covered
}

int minCameras(TreeNode* root) {
    if (minCamerasInBT(root) == -1) cameras++;
    return cameras;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int ans = minCameras(root);
    std::cout << "Minimum number of cameras needed: " << ans << std::endl;

    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
