#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
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

void printNodesDown(Node* root, int k);

int nodesAtDistanceKWithRootDistance(Node* root, int node, int k) {
    if (root == nullptr) {
        return -1;
    }

    if (root->data == node) {
        printNodesDown(root, k);
        return 0;
    }

    int leftHeight = nodesAtDistanceKWithRootDistance(root->left, node, k);
    if (leftHeight != -1) {
        if (leftHeight + 1 == k) {
            cout << root->data << endl;
        } else {
            printNodesDown(root->right, k - leftHeight - 2);
        }
        return leftHeight + 1;
    }

    int rightHeight = nodesAtDistanceKWithRootDistance(root->right, node, k);
    if (rightHeight != -1) {
        if (rightHeight + 1 == k) {
            cout << root->data << endl;
        } else {
            printNodesDown(root->left, k - rightHeight - 2);
        }
        return rightHeight + 1;
    }

    return -1;
}

void printNodesDown(Node* root, int k) {
    if (root == nullptr || k < 0) {
        return;
    }

    if (k == 0) {
        cout << root->data << endl;
        return;
    }

    printNodesDown(root->left, k - 1);
    printNodesDown(root->right, k - 1);
}

void nodesAtDistanceK(Node* root, int node, int k) {
    nodesAtDistanceKWithRootDistance(root, node, k);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->left->left->left = new Node(4);
    root->right = new Node(9);
    root->right->right = new Node(2);
    root->right->right->left = new Node(6);

    nodesAtDistanceK(root, 3, 2);

    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root;

    return 0;
}
