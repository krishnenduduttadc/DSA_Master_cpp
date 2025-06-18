#include <iostream>
using namespace std;

// TreeNode structure
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

// Helper function to flatten the binary tree
TreeNode* flattenHelper(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* leftTail = flattenHelper(root->left);
    TreeNode* rightTail = flattenHelper(root->right);

    if (leftTail != nullptr) {
        leftTail->right = root->right;  // Connect the end of the left subtree to the start of the right subtree
        root->right = root->left;       // Move the left subtree to the right
        root->left = nullptr;           // Nullify the left pointer
    }

    // Return the last node in the flattened tree
    if (rightTail != nullptr) {
        return rightTail;
    } else if (leftTail != nullptr) {
        return leftTail;
    } else {
        return root;
    }
}

// Function to flatten the binary tree
void flatten(TreeNode* root) {
    flattenHelper(root);
}

// Function to print the flattened tree
void printFlattenedTree(TreeNode* root) {
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

// Function to delete a binary tree to free memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function to test flattening
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

    // Clean up memory
    deleteTree(root);

    return 0;
}
