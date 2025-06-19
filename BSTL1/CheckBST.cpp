#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool isBST(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;
    if (root->key <= minVal || root->key >= maxVal)
        return false;
    return isBST(root->left, minVal, root->key) &&
           isBST(root->right, root->key, maxVal);
}

int main() {
    Node* root = createNode(6);
    root->left = createNode(3);
    root->right = createNode(8);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    cout << "Is BST? " << (isBST(root, INT_MIN, INT_MAX) ? "Yes" : "No") << endl;

    return 0;
}
