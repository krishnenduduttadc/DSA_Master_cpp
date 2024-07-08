#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node class definition
class Node {
public:
    int data;
    vector<Node*> children;

    Node(int val) {
        data = val;
    }
};

// Function to construct the tree from the given array
Node* construct(vector<int>& arr) {
    Node* root = nullptr;
    stack<Node*> st;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == -1) {
            st.pop();
        } else {
            Node* t = new Node(arr[i]);

            if (!st.empty()) {
                st.top()->children.push_back(t);
            } else {
                root = t;
            }

            st.push(t);
        }
    }

    return root;
}

// Function to find the path from node to root
vector<int> nodeToRootPath(Node* node, int data) {
    if (node->data == data) {
        vector<int> path = {node->data};
        return path;
    }

    for (Node* child : node->children) {
        vector<int> ptc = nodeToRootPath(child, data);
        if (!ptc.empty()) {
            ptc.push_back(node->data);
            return ptc;
        }
    }

    return {};
}

// Function to find the lowest common ancestor (LCA)
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

// Function to find the distance between two nodes
int distanceBetweenNodes(Node* node, int d1, int d2) {
    vector<int> p1 = nodeToRootPath(node, d1);
    vector<int> p2 = nodeToRootPath(node, d2);

    int i = p1.size() - 1;
    int j = p2.size() - 1;

    while (i >= 0 && j >= 0 && p1[i] == p2[j]) {
        i--;
        j--;
    }

    // Distance is calculated by adding the remaining indices + 1
    return i + j + 2;
}

// Main function
int main() {
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int d1 = 100;
    int d2 = 110;

    Node* root = construct(arr);
    int dist = distanceBetweenNodes(root, d1, d2);
    cout << dist << endl;

    return 0;
}
