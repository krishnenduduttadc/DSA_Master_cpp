#include <iostream>
#include <climits>   // For INT_MIN
#include <algorithm> // For max
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

int maxPathDown(Node* node, int& maxValue) {
    if (node == nullptr) return 0;
    
    int left = max(0, maxPathDown(node->left, maxValue)); // Ignore negative sums
    int right = max(0, maxPathDown(node->right, maxValue)); // Ignore negative sums
    
    maxValue = max(maxValue, left + right + node->key);
    
    return max(left, right) + node->key;
}

int maxPathSum(Node* root) {
    int maxValue = INT_MIN; // Initialize with minimum possible integer value
    maxPathDown(root, maxValue);
    return maxValue;
}

int main() {
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int answer = maxPathSum(root);
    cout << "The Max Path Sum for this tree is " << answer << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
