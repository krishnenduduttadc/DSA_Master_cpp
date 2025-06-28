#include <iostream>
#include <cmath> // For pow function
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

int getHeight(Node* node, bool isLeft) {
    int height = 0;
    while (node != nullptr) {
        height++;
        node = isLeft ? node->left : node->right;
    }
    return height;
}

int countNodes(Node* root) {
    if (root == nullptr) return 0;

    int leftHeight = getHeight(root, true);
    int rightHeight = getHeight(root, false);

    if (leftHeight == rightHeight) {
        return pow(2, leftHeight) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Number of nodes: " << countNodes(root) << endl;  // Output: 6

    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
