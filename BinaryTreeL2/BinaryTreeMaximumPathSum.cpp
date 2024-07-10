#include <iostream>
#include <algorithm> 
#include <climits>// for max function

using namespace std;

// Definition of a Node in the Binary Tree
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Class for calculating maximum path sum
class BinaryTreeMaximumPathSum {
private:
    int maxSum;

public:
    BinaryTreeMaximumPathSum() : maxSum(INT_MIN) {}

    int maxPathSum(Node* root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }

private:
    int helper(Node* node) {
        if (node == nullptr) return 0;

        int left = max(helper(node->left), 0);
        int right = max(helper(node->right), 0);

        int localMax = node->val + left + right;
        maxSum = max(maxSum, localMax);

        return node->val + max(left, right);
    }
};

int main() {
    BinaryTreeMaximumPathSum solution;

    // Constructing the example binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Calculating and printing the maximum path sum
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;  // Output: 16

    return 0;
}
