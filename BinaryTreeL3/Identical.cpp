#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* node = new Node;
    node->val = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool isIdentical(Node* node1, Node* node2) {
    if (node1 == nullptr && node2 == nullptr)
        return true;
    else if (node1 == nullptr || node2 == nullptr)
        return false;

    return (node1->val == node2->val) &&
           isIdentical(node1->left, node2->left) &&
           isIdentical(node1->right, node2->right);
}

int main() {
    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->right->left = createNode(4);
    root1->right->right = createNode(5);

    Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->right->left = createNode(4);

    if (isIdentical(root1, root2))
        cout << "Two Trees are identical" << endl;
    else
        cout << "Two trees are non-identical" << endl;

    return 0;
}
