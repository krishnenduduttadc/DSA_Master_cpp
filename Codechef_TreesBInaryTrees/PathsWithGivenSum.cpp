#include <iostream>
#include <vector>
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
  
    // Helper function to find all paths with a given target sum
    void findPaths(Node* node, int target, vector<int>& path, int currentSum) {
        if (node == nullptr) {
            return; // Base case: if node is NULL
        }

        // Include the current node in the path
        path.push_back(node->val);
        currentSum += node->val;

        // Check if it's a leaf node and the path sum matches the target
        if (node->left == nullptr && node->right == nullptr) {
            if (currentSum == target) {
                printPath(path); // Print the valid path
            }
        } else {
            // Continue the search in the left and right subtree
            findPaths(node->left, target, path, currentSum);
            findPaths(node->right, target, path, currentSum);
        }

        // Backtrack: remove the current node from the path
        path.pop_back();
    }

    // Helper function to print a path
    void printPath(const vector<int>& path) {
        for (int value : path) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Function to find all paths from root to leaf with the given sum
    void targetSumPaths(Node* root, int target) {
        vector<int> path; // To store the current path
        findPaths(root, target, path, 0); // Start DFS
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(1);

    // Define the target sum
    int targetSum = 22;

    // Solution instance
    Solution sol;
    
    // Find and print all paths that sum to the target
    cout << "Paths that sum to " << targetSum << " are:\n";
    sol.targetSumPaths(root, targetSum);

    return 0;
}
