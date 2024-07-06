#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinTree2LL {
private:
    static Node* prev;

public:
    static void flatten(Node* root) {
        if (root == nullptr) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    static void printList(Node* root) {
        while (root->right != nullptr) {
            std::cout << root->key << "->";
            root = root->right;
        }
        std::cout << root->key;
    }
};

Node* BinTree2LL::prev = nullptr;

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    BinTree2LL::flatten(root);
    BinTree2LL::printList(root);

    // Clean up allocated memory (not present in Java version)
    while (root != nullptr) {
        Node* temp = root;
        root = root->right;
        delete temp;
    }

    return 0;
}