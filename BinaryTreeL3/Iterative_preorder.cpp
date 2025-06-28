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

vector<int> preOrderTrav(Node* root) {
    vector<int> preOrder;
    if (root == nullptr)
        return preOrder;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* topNode = s.top();
        preOrder.push_back(topNode->key);
        s.pop();
        if (topNode->right != nullptr)
            s.push(topNode->right);
        if (topNode->left != nullptr)
            s.push(topNode->left);
    }
    return preOrder;
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

    vector<int> preOrder = preOrderTrav(root);

    cout << "The preorder traversal is : ";
    for (int i = 0; i < preOrder.size(); i++) {
        cout << preOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
