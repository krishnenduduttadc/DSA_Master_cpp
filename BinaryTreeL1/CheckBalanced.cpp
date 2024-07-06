#include <iostream>
#include <cmath> // for abs function
using namespace std;

// Definition of a binary tree node
struct Node {
    int key;
    Node *left, *right;

    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

// Function to check if the tree is balanced and return its height
int isBalanced(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int lh = isBalanced(root->left);
    if (lh == -1) {
        return -1;
    }

    int rh = isBalanced(root->right);
    if (rh == -1) {
        return -1;
    }

    if (abs(lh - rh) > 1) {
        return -1;
    } else {
        return max(lh, rh) + 1;
    }
}

int main() {
    /*
                     10
                   /   \
                 20     30
                /  \   /
              40   50  60
     */
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    cout << "Balanced? " << (isBalanced(root) == -1 ? "No" : "Yes") << endl;

    return 0;
}
