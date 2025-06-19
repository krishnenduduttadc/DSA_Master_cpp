#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

bool isValidBSTHelper(Node* node, long min, long max) {
    if (node == nullptr) return true;

    if (node->key <= min || node->key >= max)
        return false;

    return isValidBSTHelper(node->left, min, node->key) &&
           isValidBSTHelper(node->right, node->key, max);
}

bool isValidBST(Node* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = nullptr;

    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    bool validBST = isValidBST(root);
    cout << "Is the tree a valid BST? " << (validBST ? "Yes" : "No") << endl;

    return 0;
}
