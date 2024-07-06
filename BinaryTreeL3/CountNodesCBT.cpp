#include <iostream>
#include <queue>
#include <cmath> // For pow function
using namespace std;

// Definition of the Node class
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

// Function declarations
int countNodes(Node* root);
int getHeightLeft(Node* root);
int getHeightRight(Node* root);

// Function to count nodes in a Complete Binary Tree (CBT)
int countNodes(Node* root) {
    if (root == nullptr) return 0;

    int leftHeight = getHeightLeft(root);
    int rightHeight = getHeightRight(root);

    // If left and right heights are equal, it's a perfect binary tree
    if (leftHeight == rightHeight) {
        return pow(2, leftHeight + 1) - 1; // 2^(h + 1) - 1
    } else {
        // Recursively calculate nodes in left and right subtrees
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

// Function to get height of leftmost path
int getHeightLeft(Node* root) {
    int count = 0;
    while (root->left != nullptr) {
        count++;
        root = root->left;
    }
    return count;
}

// Function to get height of rightmost path
int getHeightRight(Node* root) {
    int count = 0;
    while (root->right != nullptr) {
        count++;
        root = root->right;
    }
    return count;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    int nodeCount = countNodes(root);
    cout << "Number of nodes in the Complete Binary Tree: " << nodeCount << endl;

    return 0;
}
