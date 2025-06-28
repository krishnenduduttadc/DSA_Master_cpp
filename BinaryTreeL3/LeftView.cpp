#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
   Node(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

void leftSideView(Node* root, vector<int>& result, int currDepth) {
    if (root == nullptr) {
        return;
    }
    
    if (currDepth == result.size()) {
        result.push_back(root->key);
    }

    leftSideView(root->left, result, currDepth + 1);
    leftSideView(root->right, result, currDepth + 1);
}

vector<int> lightSideView(Node* root) {
    vector<int> result;
    leftSideView(root, result, 0);
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    // Finding the left view of the binary tree
    vector<int> res = lightSideView(root);

    // Output the left view elements
    cout << "The left view of the binary tree is: ";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
