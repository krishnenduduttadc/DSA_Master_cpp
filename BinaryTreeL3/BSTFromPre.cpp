#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

// Definition of the Node class
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

// Function to construct BST from preorder traversal
Node* bstFromPreorder(int A[], int bound, int& idx) {
    // Check if all elements are processed or current element is greater than bound
    if (idx >= sizeof(A) / sizeof(A[0]) || A[idx] > bound)
        return nullptr;

    Node* root = new Node(A[idx++]); // Create new node with current element
    root->left = bstFromPreorder(A, root->key, idx); // Construct left subtree
    root->right = bstFromPreorder(A, bound, idx);    // Construct right subtree

    return root;
}

int main() {
    int A[] = {3, 2, 4};
    int idx = 0;

    Node* result = bstFromPreorder(A, INT_MAX, idx);

    // Print the root key of the constructed BST
    cout << "Root key of BST: " << result->key << endl;

    return 0;
}
