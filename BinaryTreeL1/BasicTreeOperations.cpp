#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// Node structure for the binary tree
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

class BasicTreeOperations {
public:
    // Method to print postorder traversal of the tree
    void printPostorder(Node* node) {
        if (node == nullptr)
            return;

        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->key << " ";
    }

    // Method to perform level order traversal
    void levelOrder(Node* root) {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->key << " ";

            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }

    // Method to find the longest root-to-leaf path
    vector<int> longestRootToLeafPath(Node* root) {
        if (root == nullptr)
            return vector<int>();

        vector<int> longestPath;
        vector<int> leftPath = longestRootToLeafPath(root->left);
        vector<int> rightPath = longestRootToLeafPath(root->right);

        if (leftPath.size() > rightPath.size()) {
            longestPath = leftPath;
        } else {
            longestPath = rightPath;
        }

        longestPath.insert(longestPath.begin(), root->key);
        return longestPath;
    }
};

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Creating an instance of BasicTreeOperations
    BasicTreeOperations treeOps;

    // Printing longest root-to-leaf path
    vector<int> longestPath = treeOps.longestRootToLeafPath(root);
    cout << "Longest root to leaf path: ";
    for (size_t i = 0; i < longestPath.size(); i++) {
        cout << longestPath[i];
        if (i != longestPath.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    // Printing postorder traversal
    cout << "Postorder traversal: ";
    treeOps.printPostorder(root);
    cout << endl;

    // Printing level order traversal
    cout << "Level order traversal: ";
    treeOps.levelOrder(root);
    cout << endl;

    return 0;
}
