#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int item) {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

// Function to determine the depth of a node with value `p`
int depth(Node* root, int p) {
    if (root == nullptr) {
        return 0;
    }

    if (root->data == p) {
        return 1;
    }

    int left = depth(root->left, p);
    if (left != 0) {
        return left + 1;
    }

    int right = depth(root->right, p);
    if (right != 0) {
        return right + 1;
    }

    return 0;
}

// Function to check if two nodes with values `p` and `q` are siblings
bool siblings(Node* root, int p, int q) {
    if (root == nullptr) {
        return false;
    }

    if (root->left != nullptr && root->right != nullptr) {
        if ((root->left->data == p && root->right->data == q) ||
            (root->left->data == q && root->right->data == p)) {
            return true;
        }
    }

    return siblings(root->left, p, q) || siblings(root->right, p, q);
}

// Function to determine if two nodes with values `p` and `q` are cousins
bool isCousin(Node* root, int p, int q) {
    int depth1 = depth(root, p);
    int depth2 = depth(root, q);

    if (depth1 == 0 || depth2 == 0) {
        return false;
    }

    if (depth1 == depth2) {
        return !siblings(root, p, q);
    } else {
        return false;
    }
}

int main() {
    /*
                     2
                   /   \
                 3       9
               /   \      \
             4      8      2
            /
           4
     */
    Node* root = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->left->left->left = new Node(4);
    root->right = new Node(9);
    root->right->right = new Node(2);
    root->right->right->left = new Node(6);

    cout << "Are 8 and 2 cousins? " << (isCousin(root, 8, 2) ? "Yes" : "No") << endl;

    return 0;
}
