#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* node = new Node;
    node->key = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertRec(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insertRec(root->left, key);
    } else if (key > root->key) {
        root->right = insertRec(root->right, key);
    }
    return root;
}

Node* inorderSuccessor(Node* root, Node* p) {
    Node* successor = nullptr;
    while (root != nullptr) {
        if (p->key >= root->key) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main() {
    Node* root = nullptr;

    int data[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        root = insertRec(root, data[i]);
    }

    Node* successor = inorderSuccessor(root, root->left);
    if (successor != nullptr) {
        cout << "Inorder successor of " << root->left->key << " is " << successor->key << endl;
    } else {
        cout << "No inorder successor found." << endl;
    }

    return 0;
}
