#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node* root, int x) {
    if (root == nullptr) {
        return newNode(x);
    }

    if (x < root->key) {
        root->left = insert(root->left, x);
    } else if (x > root->key) {
        root->right = insert(root->right, x);
    }

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node* getSuccessor(Node* root) {
    Node* curr = root;
    while (curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteNode(Node* root, int x) {
    if (root == nullptr) {
        return root;
    }

    if (x < root->key) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->key) {
        root->right = deleteNode(root->right, x);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* succ = getSuccessor(root->right);
        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }

    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 20);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
