#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

string serialize(TreeNode* root) {
    if (root == nullptr) return "";
    queue<TreeNode*> q;
    stringstream ss;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) {
            ss << "n ";
            continue;
        }
        ss << node->val << " ";
        q.push(node->left);
        q.push(node->right);
    }
    return ss.str();
}

TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    stringstream ss(data);
    string str;
    ss >> str;
    if (str == "n") return nullptr;
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* parent = q.front();
        q.pop();
        if (!(ss >> str)) break;
        if (str != "n") {
            TreeNode* leftChild = new TreeNode(stoi(str));
            parent->left = leftChild;
            q.push(leftChild);
        }
        if (!(ss >> str)) break;
        if (str != "n") {
            TreeNode* rightChild = new TreeNode(stoi(str));
            parent->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) {
            cout << "n ";
        } else {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    TreeNode* deserialized = deserialize(serialized);
    cout << "Deserialized tree: ";
    printTree(deserialized);

    return 0;
}
