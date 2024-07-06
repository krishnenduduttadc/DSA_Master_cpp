#include <iostream>
#include <queue>
#include <unordered_map>

// TreeNode structure definition
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

// Function to perform BFS to map parents and find the target node
TreeNode* bfsToMapParents(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& mpp, int start) {
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* res = nullptr;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->key == start) res = node;
        
        if (node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

// Function to find the maximum distance from the target node using BFS
int findMaxDistance(std::unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* target) {
    std::queue<TreeNode*> q;
    q.push(target);
    std::unordered_map<TreeNode*, int> vis;
    vis[target] = 1;
    int maxi = 0;

    while (!q.empty()) {
        int sz = q.size();
        int fl = 0;

        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left && vis.find(node->left) == vis.end()) {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && vis.find(node->right) == vis.end()) {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }

            if (mpp.find(node) != mpp.end() && vis.find(mpp[node]) == vis.end()) {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl == 1) maxi++;
    }
    return maxi;
}

// Function to calculate time to burn the entire tree
int timeToBurnTree(TreeNode* root, int start) {
    std::unordered_map<TreeNode*, TreeNode*> mpp;
    TreeNode* target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    int timeToBurn = timeToBurnTree(root, 3);
    std::cout << "Time to burn the tree starting from node 3: " << timeToBurn << std::endl;

    // Deallocating memory to avoid memory leaks
    delete root->left->left->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root;

    return 0;
}
