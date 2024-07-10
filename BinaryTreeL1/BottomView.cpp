#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Definition of a binary tree node
struct Node {
    int key;
    Node *left, *right;

    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};

// Structure to hold the node and its horizontal distance from the root
struct QueueObj {
    Node* node;
    int hd;

    QueueObj(Node* n, int h) : node(n), hd(h) {}
};

// Function to print the bottom view of the binary tree
void bottomView(Node* root) {
    if (root == nullptr)
        return;

    queue<QueueObj> q;
    map<int, int> bottomViewMap;

    q.push(QueueObj(root, 0));
    while (!q.empty()) {
        QueueObj f = q.front();
        q.pop();
        bottomViewMap[f.hd] = f.node->key;

        if (f.node->left != nullptr) {
            q.push(QueueObj(f.node->left, f.hd - 1));
        }
        if (f.node->right != nullptr) {
            q.push(QueueObj(f.node->right, f.hd + 1));
        }
    }

    for (auto const& pair : bottomViewMap) {
        cout << pair.second << " ";
    }
}

int main() {
    /*
                     1
                   /   \
                  2     3
                   \
                    4
                     \
                      5
     */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);

    cout << "Bottom view of the binary tree is:" << endl;
    bottomView(root);

    return 0;
}
