#include <iostream>
#include <cmath> // for pow function

// TreeNode structure definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// CountCompleteTreeNodes class definition
class CountCompleteTreeNodes {
public:
    // Function to count nodes in a complete binary tree
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);
        
        if (leftHeight == rightHeight) {
            return std::pow(2, leftHeight) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    // Function to calculate height of the tree
    int getHeight(TreeNode* node, bool isLeft) {
        int height = 0;
        while (node != nullptr) {
            height++;
            node = isLeft ? node->left : node->right;
        }
        return height;
    }
};

// Main function
int main() {
    CountCompleteTreeNodes solution;

    // Constructing the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Calling countNodes function and printing the result
    std::cout << "Number of nodes: " << solution.countNodes(root) << std::endl;  // Output: 6

    // Deallocating memory to avoid memory leaks
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
