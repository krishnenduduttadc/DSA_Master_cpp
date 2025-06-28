#include <iostream>
#include <algorithm> // For std::max
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

int height(Node* node, int& diameter) {
    if(node==nullptr){
        return 0;
    }
    int lefth=height(node->left,diameter);
    int righth=height(node->right,diameter);
    diameter=max(diameter,lefth+righth);
    return 1+max(lefth,righth);
}
int diameterOfBinaryTree(Node* root) {
    int dia=0;
    height(root,dia);
    return dia;
}


int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6);

    int dia = diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << dia << endl;

    return 0;
}