#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Definition of a Node in the Binary Tree
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int item) : val(item), left(nullptr), right(nullptr) {}
};

// Structure to hold vertical level and corresponding node
struct vPair {
    Node* node;
    int h1;

    vPair(Node* node, int h1) : node(node), h1(h1) {}
};

// Function to calculate width of the tree in terms of horizontal distances
void width(Node* node, int h1, pair<int, int>& minMax) {
    if (node == nullptr) return;

    minMax.first = min(minMax.first, h1);
    minMax.second = max(minMax.second, h1);

    width(node->left, h1 - 1, minMax);
    width(node->right, h1 + 1, minMax);
}

// Function to find the bottom view of the binary tree
vector<int> bottomView(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    // Finding the horizontal width of the tree
    pair<int, int> minMax = {0, 0};
    width(root, 0, minMax);

    int len = minMax.second - minMax.first + 1;
    ans.resize(len);

    queue<vPair> que;
    que.push(vPair(root, abs(minMax.first)));

    while (!que.empty()) {
        int size = que.size();
        while (size-- > 0) {
            vPair rp = que.front();
            que.pop();

            Node* node = rp.node;
            int h1 = rp.h1;

            ans[h1] = node->val;

            if (node->left != nullptr) que.push(vPair(node->left, h1 - 1));
            if (node->right != nullptr) que.push(vPair(node->right, h1 + 1));
        }
    }

    return ans;
}

int main() {
    // Constructing the example binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Finding the bottom view of the binary tree
    vector<int> ans = bottomView(root);

    // Printing the bottom view
    cout << "Bottom View of Binary Tree: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
