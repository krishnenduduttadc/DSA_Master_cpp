#include <iostream>
#include <queue>
#include <climits> // for INT_MIN and INT_MAX

using namespace std;

// Definition of a Node in the Binary Tree
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

class IterativeBasicTreeOperations {
public:
    // Method to calculate the height of the tree using BFS (level-order traversal)
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
    
    // Method to count the number of nodes in the tree using BFS (level-order traversal)
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
    
    // Method to find the maximum value in the tree using BFS (level-order traversal)
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
    
    // Method to find the minimum value in the tree using BFS (level-order traversal)
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
};

int main() {
    IterativeBasicTreeOperations solution;
    
    // Constructing the example binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    // Using the methods to demonstrate the functionality
    cout << "Height of the tree: " << solution.getHeight(root) << endl;
    cout << "Number of nodes in the tree: " << solution.getNodeCount(root) << endl;
    
    try {
        cout << "Maximum value in the tree: " << solution.getMax(root) << endl;
        cout << "Minimum value in the tree: " << solution.getMin(root) << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    
    return 0;
}
