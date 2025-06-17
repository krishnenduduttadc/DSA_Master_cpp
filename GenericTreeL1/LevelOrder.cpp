#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Node struct definition
struct Node {
    int data;
    vector<Node*> children;

    Node(int val) : data(val) {}
};

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

// Function for level order traversal
void levelOrder(Node* node) {
    if (!node) return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        cout << front->data << " ";

        for (Node* child : front->children) {
            q.push(child);
        }
    }

    cout << "." << endl;
}

// Main function
int main() {
    vector<int> arr = {
        24, 10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, 110, -1, 120, -1,
        -1, 90, -1, -1, 40, 100, -1, -1, -1
    };

    Node* root = construct(arr);
    levelOrder(root);

    return 0;
}
