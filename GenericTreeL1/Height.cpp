#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define Node using struct instead of class
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

// Function to calculate the height of the tree
int height(Node* node) {
    int maxHeight = -1;

    for (Node* child : node->children) {
        int h = height(child);
        if (h > maxHeight) {
            maxHeight = h;
        }
    }

    return maxHeight + 1;
}

// Main function
int main() {
    vector<int> arr = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};

    Node* root = construct(arr);
    cout << height(root) << endl;

    return 0;
}
