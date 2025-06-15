#include <iostream>
#include <cmath> // For pow function
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

int getHeightLeft(Node* root) {
    int count = 0;
    while (root->left != nullptr) {
        count++;
        root = root->left;
    }
    return count;
}

int getHeightRight(Node* root) {
    int count = 0;
    while (root->right != nullptr) {
        count++;
        root = root->right;
    }
    return count;
}

int countNodes(Node* root) {
    if (root == nullptr) return 0;

    int leftHeight = getHeightLeft(root);
    int rightHeight = getHeightRight(root);

    if (leftHeight == rightHeight) {
        return pow(2, leftHeight + 1) - 1;
    } else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6);

    int nodeCount = countNodes(root);
    cout << "Number of nodes in the Complete Binary Tree: " << nodeCount << endl;

    return 0;
}
