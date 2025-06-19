#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

Node* searchBST(Node* root, int val) {
    while (root != nullptr && root->key != val) {
        root = (val < root->key) ? root->left : root->right;
    }
    return root;
}

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

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++) {
        root = insertRec(root, data[i]);
    }

    Node* p = searchBST(root, 80);
    if (p) {
        cout << "Node found with key 80: " << p->key << endl;
    } else {
        cout << "Node with key 80 not found" << endl;
    }

    int ceil = findCeil(root, 80);
    cout << "Ceil of 80: " << ceil << endl;

    int floor = floorInBST(root, 20);
    cout << "Floor of 20: " << floor << endl;

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
