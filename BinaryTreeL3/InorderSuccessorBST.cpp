#include <iostream>

// Node structure definition
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

// SearchBST class for BST operations
class SearchBST {
public:
    TreeNode* insertRec(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }
        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }
        return root;
    }
};

// Function to find inorder successor in BST
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    while (root != nullptr) {
        if (p->key >= root->key) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main() {
    TreeNode* root = nullptr;
    SearchBST tree;

    int data[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        root = tree.insertRec(root, data[i]);
    }

    // Example usage to find the inorder successor of root->left
    TreeNode* successor = inorderSuccessor(root, root->left);
    if (successor != nullptr) {
        std::cout << "Inorder successor of " << root->left->key << " is " << successor->key << std::endl;
    } else {
        std::cout << "No inorder successor found." << std::endl;
    }

    return 0;
}
