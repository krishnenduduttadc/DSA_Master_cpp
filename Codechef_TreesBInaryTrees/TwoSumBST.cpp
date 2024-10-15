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
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    // Solution instance
    Solution sol;

    // Test case 1: Check if there exists a pair with sum = 40
    int targetSum1 = 40;
    cout << "Test case 1: Sum = " << targetSum1 << endl;
    sol.twoSumBST(root, targetSum1);  // Expected Output: YES

    // Test case 2: Check if there exists a pair with sum = 100
    int targetSum2 = 100;
    cout << "Test case 2: Sum = " << targetSum2 << endl;
    sol.twoSumBST(root, targetSum2);  // Expected Output: NO

    return 0;
}


/*
50 106
7 2 L
7 10 R
11 7 L
11 27 R
27 24 L
35 11 L
35 38 R
37 36 L
38 37 L
38 40 R
40 39 L
50 35 L
50 87 R
61 58 L
61 67 R
70 61 L
70 81 R
81 80 L
87 70 L
87 94 R
92 89 L
94 92 L
94 97 R
97 96 L
100 50 L
100 153 R
104 102 L
104 107 R
108 104 L
108 112 R
112 110 L
113 108 L
113 126 R
123 114 L
126 123 L
126 137 R
137 132 L
153 113 L
153 187 R
174 163 L
180 174 L
180 186 R
186 184 L
187 180 L
187 191 R
190 188 L
191 190 L
191 199 R
199 196 L

*/