#include <iostream>
#include <queue>
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
    int deepestLeavesSum(Node* root) {
        if (root == NULL)
            return 0;

        // Queue for level-order traversal (BFS)
        queue<Node*> q;
        q.push(root);

        int sum = 0;  // This will store the sum of the deepest leaves

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            sum = 0;  // Reset sum for each level

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front();
                q.pop();

                // Add the value of the current node to the sum
                sum += currentNode->val;

                // Enqueue the left child if it exists
                if (currentNode->left != NULL) {
                    q.push(currentNode->left);
                }

                // Enqueue the right child if it exists
                if (currentNode->right != NULL) {
                    q.push(currentNode->right);
                }
            }
        }

        // After the loop, 'sum' will contain the sum of the deepest leaves
        return sum;
    }
};

int main() {
    // Construct the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->right->right->right = new Node(8);

    // Solution instance
    Solution sol;
    cout << "Sum of deepest leaves: " << sol.deepestLeavesSum(root) << endl;

    return 0;
}
