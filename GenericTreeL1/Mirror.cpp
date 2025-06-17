#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // for std::reverse

using namespace std;

// Node struct definition (default access is public)
struct Node {
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

// Function to perform mirror operation on the tree
void mirror(Node* node) {
    if (!node || node->children.empty()) {
        return;
    }

    for (Node* child : node->children) {
        mirror(child);
    }

    reverse(node->children.begin(), node->children.end());
}

// Function to display the tree
void display(Node* node) {
    if (!node) return;

    cout << node->data << " -> ";
    for (Node* child : node->children) {
        cout << child->data << ", ";
    }
    cout << "." << endl;

    for (Node* child : node->children) {
        display(child);
    }
}

// Main function
int main() {
    vector<int> arr = {
        24, 10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, 110, -1, 120, -1, -1,
        90, -1, -1, 40, 100, -1, -1, -1
    };

    Node* root = construct(arr);

    cout << "Original Tree:" << endl;
    display(root);

    mirror(root);

    cout << "\nMirrored Tree:" << endl;
    display(root);

    return 0;
}
