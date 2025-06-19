#include <iostream>
#include <stack>
#include <vector>
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

vector<int> postOrderTraversal(Node* root) {
    vector<int> postOrder;
    if (root == nullptr)
        return postOrder;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    while (!s2.empty()) {
        Node* temp = s2.top();
        s2.pop();
        postOrder.push_back(temp->key);
    }

    return postOrder;
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

    vector<int> postOrder = postOrderTraversal(root);

    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++) {
        cout << postOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
