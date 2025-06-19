#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

   Node(int item) {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

void printNodesWithoutSibling(Node* root) {
    if (root == nullptr)
        return;

    if ((root->left == nullptr && root->right != nullptr) || 
        (root->left != nullptr && root->right == nullptr)) {
        cout << root->data << " ";
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    cout << "Nodes without siblings: ";
    printNodesWithoutSibling(root);
    cout << endl;

    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
