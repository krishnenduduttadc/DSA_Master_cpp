#include <iostream>
#include <string>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void pathToLeafFromRoot(Node* node, string path, int sum, int lo, int hi) {
    if (node == nullptr)
        return;

    path += to_string(node->data) + " ";
    sum += node->data;

    if (node->left == nullptr && node->right == nullptr) {
        if (sum >= lo && sum <= hi) {
            cout << path << endl;
        }
        return;
    }

    pathToLeafFromRoot(node->left, path, sum, lo, hi);
    pathToLeafFromRoot(node->right, path, sum, lo, hi);
}

int main() {
    int lo = 150;
    int hi = 250;

    Node* root = new Node(50,
                          new Node(25,
                                   new Node(12, nullptr, nullptr),
                                   new Node(37,
                                            new Node(30, nullptr, nullptr),
                                            new Node(40, nullptr, nullptr))),
                          new Node(75,
                                   new Node(62,
                                            new Node(60, nullptr, nullptr),
                                            new Node(70, nullptr, nullptr)),
                                   new Node(87, nullptr, nullptr)));

    // Call function to find paths from root to leaf nodes with sum in range [lo, hi]
    pathToLeafFromRoot(root, "", 0, lo, hi);

    // Clean up dynamically allocated memory
    delete root->right->left->right;
    delete root->right->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
