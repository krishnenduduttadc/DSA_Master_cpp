#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int item) : data(item), left(nullptr), right(nullptr) {}
};

// Function to check if a node with value `x` is present in the binary tree
bool isNodePresent(Node* root, int x) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == x) {
        return true;
    }

    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}

int main() {
    /*
                     10
                   /    \
                 20      30
                /  \     /
              40    50  60
     */
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    int x = 400;
    cout << "Is node " << x << " present? " << (isNodePresent(root, x) ? "Yes" : "No") << endl;

    return 0;
}
