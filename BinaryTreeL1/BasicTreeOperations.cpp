#include <iostream>
#include <queue>
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

void printPostorder(Node* node) {
    if (node == nullptr)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}

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

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> longestPath = longestRootToLeafPath(root);
    cout << "Longest root to leaf path: ";
    for (size_t i = 0; i < longestPath.size(); i++) {
        cout << longestPath[i];
        if (i != longestPath.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    printPostorder(root);
    cout << endl;

    cout << "Level order traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
