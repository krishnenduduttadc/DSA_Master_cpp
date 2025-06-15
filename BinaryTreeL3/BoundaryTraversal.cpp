#include <iostream>
#include <vector>
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

bool isLeaf(Node* root) {
    return (root->left == nullptr && root->right == nullptr);
}

void addLeftBoundary(Node* root, vector<int>& res) {
    Node* cur = root->left;
    while (cur != nullptr) {
        if (!isLeaf(cur))
            res.push_back(cur->key);
        if (cur->left != nullptr)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(Node* root, vector<int>& res) {
    Node* cur = root->right;
    vector<int> tmp;
    while (cur != nullptr) {
        if (!isLeaf(cur))
            tmp.push_back(cur->key);
        if (cur->right != nullptr)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i) {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->key);
        return;
    }
    if (root->left != nullptr)
        addLeaves(root->left, res);
    if (root->right != nullptr)
        addLeaves(root->right, res);
}

vector<int> printBoundary(Node* node) {
    vector<int> ans;
    if (!isLeaf(node))
        ans.push_back(node->key);
    addLeftBoundary(node, ans);
    addLeaves(node, ans);
    addRightBoundary(node, ans);
    return ans;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->left->left->right = createNode(4);
    root->left->left->right->left = createNode(5);
    root->left->left->right->right = createNode(6);
    root->right = createNode(7);
    root->right->right = createNode(8);
    root->right->right->left = createNode(9);
    root->right->right->left->left = createNode(10);
    root->right->right->left->right = createNode(11);

    vector<int> boundaryTraversal = printBoundary(root);

    cout << "The Boundary Traversal is : ";
    for (int i = 0; i < boundaryTraversal.size(); i++) {
        cout << boundaryTraversal[i] << " ";
    }
    cout << endl;

    return 0;
}
