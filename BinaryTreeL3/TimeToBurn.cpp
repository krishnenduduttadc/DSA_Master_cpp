#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure definition
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) : key(x), left(nullptr), right(nullptr) {}
};

// Function to perform BFS to map parents and find the target node
Node* bfsToMapParents(Node* root, unordered_map<Node*, Node*>& mpp, int start) {
    queue<Node*> q;
    q.push(root);
    Node* res = nullptr;

    while (!q.empty()) {
        Node* node = q.front();
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
int findMaxDistance(unordered_map<Node*, Node*>& mpp, Node* target) {
    queue<Node*> q;
    q.push(target);
    unordered_map<Node*, int> vis;
    vis[target] = 1;
    int maxi = 0;

    while (!q.empty()) {
        int sz = q.size();
        int fl = 0;

        for (int i = 0; i < sz; i++) {
            Node* node = q.front();
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
int timeToBurnTree(Node* root, int start) {
    unordered_map<Node*, Node*> mpp;
    Node* target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

// Main function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    int timeToBurn = timeToBurnTree(root, 3);
    cout << "Time to burn the tree starting from node 3: " << timeToBurn << endl;

    // Deallocating memory to avoid memory leaks
    delete root->left->left->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root;

    return 0;
}
