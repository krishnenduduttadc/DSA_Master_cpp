#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};

// Structure to store node and its horizontal distance
struct QueueObj {
    Node* node;
    int hd;

     QueueObj(Node* node, int hd) {
        this->node = node;
        this->hd = hd;
    }
};

// Function to print the top view of the binary tree
void topView(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<QueueObj> q;
    map<int, int> topViewMap;

    q.push(QueueObj(root, 0));

    while (!q.empty()) {
        QueueObj f = q.front();
        q.pop();

        // If this horizontal distance is not in the map, add it to the map
        if (topViewMap.find(f.hd) == topViewMap.end()) {
            topViewMap[f.hd] = f.node->key;
        }

        // Enqueue left and right children with horizontal distance
        if (f.node->left != nullptr) {
            q.push(QueueObj(f.node->left, f.hd - 1));
        }
        if (f.node->right != nullptr) {
            q.push(QueueObj(f.node->right, f.hd + 1));
        }
    }

    // Print the top view nodes
    for (auto it = topViewMap.begin(); it != topViewMap.end(); ++it) {
        cout << it->second << " ";
    }
    cout << endl;
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

    cout << "Top view of the binary tree is:" << endl;
    topView(root);

    // Clean up dynamically allocated memory
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
