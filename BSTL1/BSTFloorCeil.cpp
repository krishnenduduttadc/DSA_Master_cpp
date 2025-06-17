#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

// Helper function to create a new node
Node* newNode(int item) {
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = nullptr;
    return temp;
}

// Function to find floor
Node* findFloor(Node* node, int x) {
    Node* res = nullptr;
    while (node != nullptr) {
        if (node->data == x) {
            return node;
        }
        if (node->data > x) {
            node = node->left;
        } else {
            res = node;
            node = node->right;
        }
    }
    return res;
}

// Function to find ceil
int findCeil(Node* node, int x) {
    if (node == nullptr) {
        return -1;
    }
    if (node->data == x) {
        return node->data;
    }
    if (node->data < x) {
        return findCeil(node->right, x);
    }
    int ceil = findCeil(node->left, x);
    return (ceil >= x) ? ceil : node->data;
}

int main() {
    // Construct the BST
    Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);

    // Find floor and ceiling
    Node* floorNode = findFloor(root, 7);
    int floorValue = (floorNode != nullptr) ? floorNode->data : -1;
    cout << "The floor is: " << floorValue << endl;

    int ceilValue = findCeil(root, 7);
    cout << "The ceiling is: " << ceilValue << endl;

    return 0;
}
