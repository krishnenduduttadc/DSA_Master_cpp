#include <iostream>
#include <algorithm> // For max() function
using namespace std;

struct node {
    int val;
    struct node* left;
    struct node* right;
    int ht;
} ;

int height(node* n) {
    if (n == NULL)
        return -1;
    return n->ht;
}

int balanceFactor(node* n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

node* rotateRight(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->ht = max(height(y->left), height(y->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

node* rotateLeft(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

node* newNode(int value) {
    node* n = new node();
    n->val = value;
    n->left = NULL;
    n->right = NULL;
    n->ht = 0;  // Height of the node is set to 0
    return n;
}

node* insert(node* root, int new_val) {
    // Perform the normal BST insert
    if (root == NULL)
        return newNode(new_val);

    if (new_val < root->val)
        root->left = insert(root->left, new_val);
    else if (new_val > root->val)
        root->right = insert(root->right, new_val);
    else
        return root; // Duplicate values are not allowed

    // Update the height of the ancestor node
    root->ht = 1 + max(height(root->left), height(root->right));

    // Get the balance factor
    int bf = balanceFactor(root);

    // If the node becomes unbalanced, there are 4 cases:

    // Case 1 - Left Left
    if (bf > 1 && new_val < root->left->val)
        return rotateRight(root);

    // Case 2 - Right Right
    if (bf < -1 && new_val > root->right->val)
        return rotateLeft(root);

    // Case 3 - Left Right
    if (bf > 1 && new_val > root->left->val) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Case 4 - Right Left
    if (bf < -1 && new_val < root->right->val) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // Return the (unchanged) root pointer
    return root;
}

// In-order traversal to print the tree in sorted order
void inOrderTraversal(node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal to show the structure of the AVL tree
void preOrderTraversal(node* root) {
    if (root != NULL) {
        cout << root->val << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Main function to test the AVL tree implementation
int main() {
    node* root = NULL;

    // Insert values into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // In-order traversal of the AVL tree (should be sorted)
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Pre-order traversal of the AVL tree (shows the structure)
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}
