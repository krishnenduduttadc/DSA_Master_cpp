#include <iostream>
#include <queue>
#include <climits> // for INT_MIN and INT_MAX

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int getHeight(Node* root) {
    if (root == nullptr) return 0;
    
    queue<Node*> q;
    q.push(root);
    int height = 0;
    
    while (!q.empty()) {
        int levelSize = q.size();
        height++;
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
    }
    
    return height;
}

int getNodeCount(Node* root) {
    if (root == nullptr) return 0;
    
    queue<Node*> q;
    q.push(root);
    int count = 0;
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        count++;
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
    
    return count;
}

int getMax(Node* root) {
    if (root == nullptr) throw invalid_argument("Tree is empty");
    
    queue<Node*> q;
    q.push(root);
    int maxValue = INT_MIN;
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        maxValue = max(maxValue, node->val);
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
    
    return maxValue;
}

int getMin(Node* root) {
    if (root == nullptr) throw invalid_argument("Tree is empty");
    
    queue<Node*> q;
    q.push(root);
    int minValue = INT_MAX;
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        minValue = min(minValue, node->val);
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
    
    return minValue;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << "Height of the tree: " << getHeight(root) << endl;
    cout << "Number of nodes in the tree: " << getNodeCount(root) << endl;
    
    try {
        cout << "Maximum value in the tree: " << getMax(root) << endl;
        cout << "Minimum value in the tree: " << getMin(root) << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    
    return 0;
}
