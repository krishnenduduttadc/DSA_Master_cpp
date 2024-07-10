#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left = nullptr, Node* right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

// Function to print level-wise traversal of the binary tree
void printLevelWise(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left != nullptr) {
                q.push(front->left);
            }
            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

// Function to remove all leaf nodes from the binary tree
Node* removeAllLeaves(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->left == nullptr && root->right == nullptr) {
        delete root; // Free memory for leaf node
        return nullptr;
    }

    root->left = removeAllLeaves(root->left);
    root->right = removeAllLeaves(root->right);
    return root;
}

int main() {
    // Hardcoded tree construction
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    cout << "Original Binary Tree:" << endl;
    printLevelWise(root);
    cout << endl;

    // Remove all leaf nodes
    Node* modifiedRoot = removeAllLeaves(root);

    cout << "Binary Tree after removing leaf nodes:" << endl;
    printLevelWise(modifiedRoot);

    // Clean up dynamically allocated memory
    delete modifiedRoot->right->left;
    delete modifiedRoot->left->right;
    delete modifiedRoot->left->left;
    delete modifiedRoot->right;
    delete modifiedRoot->left;
    delete modifiedRoot;

    return 0;
}
