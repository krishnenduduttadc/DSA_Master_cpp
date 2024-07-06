#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>

// TreeNode structure definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// SerializeDeserializeBinaryTree class definition
class SerializeDeserializeBinaryTree {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (root == nullptr) return "null";
        
        std::stringstream ss;
        std::queue<TreeNode*> q;
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
        
        std::string result = ss.str();
        return result.substr(0, result.length() - 1); // Remove last comma
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data == "null") return nullptr;
        
        std::vector<std::string> nodes;
        std::stringstream ss(data);
        std::string item;
        
        while (std::getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        
        TreeNode* root = new TreeNode(std::stoi(nodes[0]));
        std::queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        
        while (!q.empty() && i < nodes.size()) {
            TreeNode* parent = q.front();
            q.pop();
            
            if (nodes[i] != "null") {
                parent->left = new TreeNode(std::stoi(nodes[i]));
                q.push(parent->left);
            }
            i++;
            
            if (i < nodes.size() && nodes[i] != "null") {
                parent->right = new TreeNode(std::stoi(nodes[i]));
                q.push(parent->right);
            }
            i++;
        }
        
        return root;
    }
};

// Function to delete the tree to avoid memory leaks
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function
int main() {
    SerializeDeserializeBinaryTree serDeser;

    // Constructing the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serializing the tree
    std::string serialized = serDeser.serialize(root);
    std::cout << "Serialized: " << serialized << std::endl;

    // Deserializing the serialized string
    TreeNode* deserialized = serDeser.deserialize(serialized);
    std::string reserialized = serDeser.serialize(deserialized);
    std::cout << "Deserialized: " << reserialized << std::endl;

    // Deleting the trees to free allocated memory
    deleteTree(root);
    deleteTree(deserialized);

    return 0;
}
