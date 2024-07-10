#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform mirror transformation of a binary tree
void mirrorBinaryTree(Node* root) {
    if (root == nullptr)
        return;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    // Swap left and right children of the current node
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Function to print level-wise traversal of a binary tree
void printLevelWise(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* front = q.front();
            q.pop();
            cout << front->data << " ";

            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
        cout << endl;
    }
}

int main() {
    // Hardcoded tree construction
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    // Print original tree
    cout << "Original Tree (Level-wise traversal):" << endl;
    printLevelWise(root);
    cout << endl;

    // Perform mirror transformation
    mirrorBinaryTree(root);

    // Print mirrored tree
    cout << "Mirrored Tree (Level-wise traversal):" << endl;
    printLevelWise(root);

    // Clean up dynamically allocated memory
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
