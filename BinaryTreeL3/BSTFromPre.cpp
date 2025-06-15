#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int item) {
    Node* newNode = new Node;
    newNode->key = item;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* bstFromPreorderHelper(int A[], int size, int bound, int& idx) {
    if (idx >= size || A[idx] > bound)
        return nullptr;

    Node* root = createNode(A[idx++]);
    root->left = bstFromPreorderHelper(A, size, root->key, idx);
    root->right = bstFromPreorderHelper(A, size, bound, idx);

    return root;
}

int main() {
    int A[] = {3, 2, 4};
    int idx = 0;
    int size = sizeof(A) / sizeof(A[0]);

    Node* result = bstFromPreorderHelper(A, size, INT_MAX, idx);

    // Print the root key of the constructed BST
    cout << "Root key of BST: " << result->key << endl;

    return 0;
}
