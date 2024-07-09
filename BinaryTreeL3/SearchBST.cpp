#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

// Function to search for a node with a given key in BST
Node* searchBST(Node* root, int val) {
    while (root != nullptr && root->key != val) {
        root = (val < root->key) ? root->left : root->right;
    }
    return root;
}

// Function to insert a new key in BST recursively
Node* insertRec(Node* root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return root;
    }
    if (key < root->key) {
        root->left = insertRec(root->left, key);
    } else if (key > root->key) {
        root->right = insertRec(root->right, key);
    }
    return root;
}

// Function to find the smallest key >= given key (Ceil) in BST
int findCeil(Node* root, int key) {
    int ceil = -1;
    while (root != nullptr) {
        if (root->key == key) {
            ceil = root->key;
            return ceil;
        }
        if (key > root->key) {
            root = root->right;
        } else {
            ceil = root->key;
            root = root->left;
        }
    }
    return ceil;
}

// Function to find the largest key <= given key (Floor) in BST
int floorInBST(Node* root, int key) {
    int floor = -1;
    while (root != nullptr) {
        if (root->key == key) {
            floor = root->key;
            return floor;
        }
        if (key > root->key) {
            floor = root->key;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

// Utility function to print the BST (inorder traversal)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Insert elements into BST
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++) {
        root = insertRec(root, data[i]);
    }

    // Test searchBST method
    Node* p = searchBST(root, 80);
    if (p) {
        cout << "Node found with key 80: " << p->key << endl;
    } else {
        cout << "Node with key 80 not found" << endl;
    }

    // Test findCeil method
    int ceil = findCeil(root, 80);
    cout << "Ceil of 80: " << ceil << endl;

    // Test floorInBST method
    int floor = floorInBST(root, 20);
    cout << "Floor of 20: " << floor << endl;

    // Print inorder traversal of the BST
    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
