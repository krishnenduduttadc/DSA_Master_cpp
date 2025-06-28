#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> diagonalOrder(Node* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    queue<Node*> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        vector<int> smallAns;

        while (size--) {
            Node* node = que.front();
            que.pop();

            while (node != nullptr) {
                smallAns.push_back(node->val);
                if (node->left) que.push(node->left);
                node = node->right;
            }
        }

        ans.push_back(smallAns);
    }

    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = diagonalOrder(root);

    cout << "Diagonal Order Traversal:\n";
    for (const auto level : ans) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << "\n";
    }

    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
