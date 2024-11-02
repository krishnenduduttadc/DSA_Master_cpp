#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int node_value) {
        val = node_value;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to find if there exists a pair with a given sum in the BST
    void findPairWithSum(Node* root, int S, unordered_set<int>& seen, bool& found) {
        if (root == nullptr || found) return;

        // Traverse the left subtree
        findPairWithSum(root->left, S, seen, found);

        // Check if the complement exists in the set
        int complement = S - root->val;
        if (seen.find(complement) != seen.end()) {
            found = true; // Pair found
            return;
        }

        // Add current node value to the set
        seen.insert(root->val);

        // Traverse the right subtree
        findPairWithSum(root->right, S, seen, found);
    }

    // Wrapper function to call the helper and check for two-sum in the BST
    void twoSumBST(Node* root, int S) {
        unordered_set<int> seen;
        bool found = false;
        findPairWithSum(root, S, seen, found);

        if (found) {
            cout << "YES\n"; // If a pair is found
        } else {
            cout << "NO\n";  // If no pair is found
        }
    }
};

int main() {
    // Create a sample Binary Search Tree (BST)
    Node* root = new Node(50);
    root->left = new Node(35);
    root->right = new Node(106);
    root->left->left = new Node(27);
    root->left->right = new Node(38);
    root->left->left->left = new Node(11);
    root->left->left->right = new Node(24);
    root->left->right->left = new Node(36);
    root->left->right->right = new Node(40);
    root->right->left = new Node(61);
    root->right->right = new Node(153);
    root->right->left->left = new Node(58);
    root->right->left->right = new Node(67);
    root->right->right->left = new Node(113);
    root->right->right->right = new Node(187);
    root->right->right->left->left = new Node(108);
    root->right->right->left->right = new Node(126);
    root->right->right->right->left = new Node(180);
    root->right->right->right->right = new Node(191);

    // Solution instance
    Solution sol;

    // Test case 1: Check if there exists a pair with sum = 100
    int targetSum1 = 100;
    cout << "Test case 1: Sum = " << targetSum1 << endl;
    sol.twoSumBST(root, targetSum1);  // Expected Output: YES

    // Test case 2: Check if there exists a pair with sum = 300
    int targetSum2 = 300;
    cout << "Test case 2: Sum = " << targetSum2 << endl;
    sol.twoSumBST(root, targetSum2);  // Expected Output: NO

    return 0;
}
