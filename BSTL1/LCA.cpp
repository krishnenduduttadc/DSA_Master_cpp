#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    
    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};

Node* getLCA(Node* node, int n1, int n2) {
    if (node == nullptr) {
        return nullptr;
    }
    
    if (node->key > n1 && node->key > n2) {
        return getLCA(node->left, n1, n2);
    }
    
    if (node->key < n1 && node->key < n2) {
        return getLCA(node->right, n1, n2);
    }
    
    return node;
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    
    Node* lca = getLCA(root, 3, 7);
    cout << "LCA of 3 and 7 is: " << lca->key << endl;
    
    return 0;
}
