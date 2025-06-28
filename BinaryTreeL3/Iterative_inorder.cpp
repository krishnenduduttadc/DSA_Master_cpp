#include <iostream>
#include <vector>
#include <stack>
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

vector<int> inOrderTrav(Node* root) {
    vector<int> inOrder;
    stack<Node*> s;
    Node* curr = root;

    while (true) {
        if (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        } else {
            if (s.empty()) break;
            curr = s.top();
            inOrder.push_back(curr->key);
            s.pop();
            curr = curr->right;
        }
    }
    return inOrder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<int> inOrder = inOrderTrav(root);

    cout << "The inorder traversal is : ";
    for (int i = 0; i < inOrder.size(); i++) {
        cout << inOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
