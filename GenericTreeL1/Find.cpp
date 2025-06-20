#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
    Node(int val)  {data=val;}
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

bool findNode(Node* node, int data) {
    if (node->data == data) return true;

    for (Node* child : node->children) {
        if (findNode(child, data)) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {
        10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, 110, -1, 120, -1, -1,
        90, -1, -1, 40, 100, -1, -1, -1
    };
    int data = 120;

    Node* root = constructTree(arr);
    bool found = findNode(root, data);
    cout << boolalpha << found << endl;

    return 0;
}
