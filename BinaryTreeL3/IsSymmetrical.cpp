#include <iostream>
#include <queue> // for queue
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

bool isSymmetricHelp(Node* left, Node* right);

bool isSymmetric(Node* root) {
    return root == nullptr || isSymmetricHelp(root->left, root->right);
}

bool isSymmetricHelp(Node* left, Node* right) {
    if (left == nullptr || right == nullptr)
        return left == right;
    if (left->key != right->key)
        return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

Node* newNode(int key) {
    return new Node(key);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);

    bool isSym = isSymmetric(root);
    if (isSym)
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}
