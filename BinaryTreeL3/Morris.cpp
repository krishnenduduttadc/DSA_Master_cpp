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

vector<int> preorderTraversal(Node* root) {
    vector<int> preorder;
    Node* cur = root;
    
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            preorder.push_back(cur->key);
            cur = cur->right;
        } else {
            Node* prev = cur->left;
            while (prev->right != nullptr && prev->right != cur) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = cur;
                preorder.push_back(cur->key);
                cur = cur->left;
            } else {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    
    return preorder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> preorder = preorderTraversal(root);

    cout << "The Preorder Traversal is: ";
    for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i] << " ";
    }
    cout << endl;

    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
