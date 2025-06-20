#include <iostream>
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

TreeNode* flattenHelper(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* leftTail = flattenHelper(root->left);
    TreeNode* rightTail = flattenHelper(root->right);

    if (leftTail != nullptr) {
        leftTail->right = root->right;  // Connect the end of the left subtree to the start of the right subtree
        root->right = root->left;       // Move the left subtree to the right
        root->left = nullptr;           // Nullify the left pointer
    }

    if (rightTail != nullptr) {
        return rightTail;
    } else if (leftTail != nullptr) {
        return leftTail;
    } else {
        return root;
    }
}

void flatten(TreeNode* root) {
    flattenHelper(root);
}

void printFlattenedTree(TreeNode* root) {
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Creating a sample binary tree:
    //     1
    //    / \
    //   2   5
    //  / \   \
    // 3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    cout << "Original Tree:" << endl;
    printFlattenedTree(root); // This will just print the root node

    flatten(root);

    cout << "Flattened Tree:" << endl;
    printFlattenedTree(root);

    deleteTree(root);

    return 0;
}
