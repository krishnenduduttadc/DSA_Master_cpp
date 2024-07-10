#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

// Function to print level-wise traversal of the binary tree
void printLevelWise(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left != nullptr) {
                q.push(front->left);
            }
            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

// Function to print zigzag traversal of the binary tree
void printZigZag(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    stack<int> s;
    bool reverse = false;
    q.push(root);

    while (!q.empty()) {
        int cnt = q.size();
        for (int i = 0; i < cnt; ++i) {
            Node* front = q.front();
            q.pop();
            if (reverse) {
                s.push(front->data);
            } else {
                cout << front->data << " ";
            }
            if (front->left != nullptr) {
                q.push(front->left);
            }
            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
        if (reverse) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    cout << "Level-wise traversal:" << endl;
    printLevelWise(root);

    cout << "\n------------------------\n";

    cout << "Zigzag traversal:" << endl;
    printZigZag(root);

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
