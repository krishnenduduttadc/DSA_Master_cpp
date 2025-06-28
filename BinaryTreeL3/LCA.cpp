#include <iostream>
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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    // Base case: if root is null or root is one of p or q, return root
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    
    // Recursively search left and right subtrees
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    // Result conditions
    if (left == nullptr) {
        return right;
    } else if (right == nullptr) {
        return left;
    } else {
        return root;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    Node* lca = lowestCommonAncestor(root, root->left->right, root->left->left->left);

    cout << "Lowest Common Ancestor (LCA) key: " << lca->key << endl;

    return 0;
}
