#include <iostream>
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

Node* insertRec(Node* root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return root;
    }
    if (key < root->key) {
        root->left = insertRec(root->left, key);
    } else if (key > root->key) {
        root->right = insertRec(root->right, key);
    }
    return root;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == nullptr) return nullptr;
    int curr = root->key;
    if (curr < p->key && curr < q->key) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (curr > p->key && curr > q->key) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

int main() {
    Node* root = nullptr;

    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++) {
        root = insertRec(root, data[i]);
    }

    Node* p = root->left->left;   // Node with key 20
    Node* q = root->right;        // Node with key 70
    Node* lca = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->key << " and " << q->key << " is: " << lca->key << endl;

    return 0;
}
