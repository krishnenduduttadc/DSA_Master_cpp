#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// TreeNode structure definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (root == nullptr) return "null";
    
    stringstream ss;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node == nullptr) {
            ss << "null,";
        } else {
            ss << node->val << ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    
    string result = ss.str();
    return result.substr(0, result.length() - 1); // Remove last comma
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data == "null") return nullptr;
    
    vector<string> nodes;
    stringstream ss(data);
    string item;
    
    while (getline(ss, item, ',')) {
        nodes.push_back(item);
    }
    
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (!q.empty() && i < nodes.size()) {
        TreeNode* parent = q.front();
        q.pop();
        
        if (nodes[i] != "null") {
            parent->left = new TreeNode(stoi(nodes[i]));
            q.push(parent->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != "null") {
            parent->right = new TreeNode(stoi(nodes[i]));
            q.push(parent->right);
        }
        i++;
    }
    
    return root;
}

// Function to delete the tree to avoid memory leaks
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function
int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serializing the tree
    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    // Deserializing the serialized string
    TreeNode* deserialized = deserialize(serialized);
    string reserialized = serialize(deserialized);
    cout << "Deserialized: " << reserialized << endl;

    // Deleting the trees to free allocated memory
    deleteTree(root);
    deleteTree(deserialized);

    return 0;
}
