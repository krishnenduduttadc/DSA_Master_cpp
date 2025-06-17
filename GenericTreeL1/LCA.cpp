#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node struct definition
struct Node {
    int data;
    vector<Node*> children;

    Node(int val) : data(val) {}
};

// Function to display the tree (optional)
void display(Node* node) {
    cout << node->data << " -> ";
    for (Node* child : node->children) {
        cout << child->data << ", ";
    }
    cout << "." << endl;

    for (Node* child : node->children) {
        display(child);
    }
}

// Function to construct the tree from the given array
Node* construct(const vector<int>& arr) {
    Node* root = nullptr;
    stack<Node*> st;

    for (int val : arr) {
        if (val == -1) {
            st.pop();
        } else {
            Node* node = new Node(val);
            if (!st.empty()) {
                st.top()->children.push_back(node);
            } else {
                root = node;
            }
            st.push(node);
        }
    }

    return root;
}

// Function to find path from root to a given node data
vector<int> nodeToRootPath(Node* node, int data) {
    if (node->data == data) {
        return {node->data};
    }

    for (Node* child : node->children) {
        vector<int> path = nodeToRootPath(child, data);
        if (!path.empty()) {
            path.push_back(node->data);
            return path;
        }
    }

    return {};
}

// Function to find Lowest Common Ancestor (LCA) of two nodes
int lca(Node* node, int d1, int d2) {
    vector<int> p1 = nodeToRootPath(node, d1);
    vector<int> p2 = nodeToRootPath(node, d2);

    int i = p1.size() - 1;
    int j = p2.size() - 1;

    while (i >= 0 && j >= 0 && p1[i] == p2[j]) {
        i--;
        j--;
    }

    return p1[i + 1];
}

// Main function
int main() {
    vector<int> arr = {
        24, 10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, 110, -1, 120, -1,
        -1, 90, -1, -1, 40, 100, -1, -1, -1
    };
    int d1 = 120;
    int d2 = 80;

    Node* root = construct(arr);
    int lcaValue = lca(root, d1, d2);
    cout << lcaValue << endl;

    // Uncomment below to display the tree
    // display(root);

    return 0;
}
