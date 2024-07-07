#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TopView {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> topViewNodes;
        if (!root) {
            return topViewNodes;
        }

        map<int, int> hdMap; // TreeMap equivalent in Java
        queue<pair<TreeNode*, int>> q; // Queue to store node and its horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (hdMap.find(hd) == hdMap.end()) { // If hd is not in the map, add it
                hdMap[hd] = node->val;
            }

            if (node->left) {
                q.push({node->left, hd - 1});
            }

            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Extract values from map to result vector
        for (const auto& pair : hdMap) {
            topViewNodes.push_back(pair.second);
        }

        return topViewNodes;
    }
};

// Utility function to create a new node
TreeNode* newNode(int key) {
    TreeNode* node = new TreeNode(key);
    return node;
}

int main() {
    TopView tree;
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    vector<int> result = tree.topView(root);

    // Print the top view of the binary tree
    cout << "Top view of the binary tree:" << endl;
    for (int nodeValue : result) {
        cout << nodeValue << " ";
    }
    cout << endl;

    // Clean up memory (optional in this example)
    // You may need to delete nodes if not using smart pointers
    return 0;
}
