#include <iostream>
#include <algorithm>
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

pair<bool, int> isBalancedHelper(Node* root) {
    if (root == nullptr)
        return {true, 0};

    auto left = isBalancedHelper(root->left);
    auto right = isBalancedHelper(root->right);

    if (!left.first || !right.first)
        return {false, -1};

    if (abs(left.second - right.second) > 1)
        return {false, -1};

    return {true, max(left.second, right.second) + 1};
}

bool isBalanced(Node* root) {
    return isBalancedHelper(root).first;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    bool balanced = isBalanced(root);
    cout << "Is the tree balanced? " << (balanced ? "Yes" : "No") << endl;

    return 0;
}
