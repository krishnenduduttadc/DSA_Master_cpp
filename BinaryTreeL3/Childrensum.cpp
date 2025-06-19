#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int item) {
    Node* newNode = new Node;
    newNode->key = item;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void reorder(Node* root) {
    if (root == nullptr) return;

    int child = 0;
    if (root->left != nullptr) {
        child += root->left->key;
    }
    if (root->right != nullptr) {
        child += root->right->key;
    }

    if (child < root->key) {
        if (root->left != nullptr) root->left->key = root->key;
        else if (root->right != nullptr) root->right->key = root->key;
    }

    reorder(root->left);
    reorder(root->right);

    int tot = 0;
    if (root->left != nullptr) tot += root->left->key;
    if (root->right != nullptr) tot += root->right->key;
    if (root->left != nullptr || root->right != nullptr) root->key = tot;
}

void changeTree(Node* root) {
    reorder(root);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(35);
    root->left->left = createNode(2);
    root->left->right = createNode(3);
    root->right = createNode(10);
    root->right->left = createNode(5);
    root->right->right = createNode(2);

    changeTree(root);

    cout << "Modified Tree:" << endl;
    cout << "Root: " << root->key << endl;
    cout << "Left: " << root->left->key << ", Left Left: " << root->left->left->key << ", Left Right: " << root->left->right->key << endl;
    cout << "Right: " << root->right->key << ", Right Left: " << root->right->left->key << ", Right Right: " << root->right->right->key << endl;

    return 0;
}
