#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    vector<Node*> children;
    Node(int val)  {data = val; }
};

Node* constructTree(const vector<int>& arr) {
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

int distanceBetweenNodes(Node* root, int d1, int d2) {
    vector<int> path1 = nodeToRootPath(root, d1);
    vector<int> path2 = nodeToRootPath(root, d2);

    int i = path1.size() - 1;
    int j = path2.size() - 1;

    while (i >= 0 && j >= 0 && path1[i] == path2[j]) {
        i--;
        j--;
    }

    return i + j + 2;
}

int main() {
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1,
                       30, 70, -1, 80, 110, -1, 120, -1, -1,
                       90, -1, -1, 40, 100, -1, -1, -1};

    int d1 = 100;
    int d2 = 110;

    Node* root = constructTree(arr);
    int dist = distanceBetweenNodes(root, d1, d2);
    cout << "Distance between " << d1 << " and " << d2 << " is: " << dist << endl;

    return 0;
}
