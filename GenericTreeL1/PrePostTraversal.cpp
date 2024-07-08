#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Node structure definition
struct Node {
    int data;
    vector<Node*> children;
};

// Function to display the tree structure
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

// Function to construct the tree from an array
Node* construct(vector<int>& arr) {
    Node* root = nullptr;
    vector<Node*> st;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == -1) {
            st.pop_back();
        } else {
            Node* t = new Node();
            t->data = arr[i];

            if (!st.empty()) {
                st.back()->children.push_back(t);
            } else {
                root = t;
            }

            st.push_back(t);
        }
    }

    return root;
}

// Function to perform pre-order, post-order, and edge printing traversals
void traversals(Node* node) {
    // Print Node Pre
    cout << "Node Pre " << node->data << endl;

    // Print Edge Pre
    for (Node* child : node->children) {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traversals(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }

    // Print Node Post
    cout << "Node Post " << node->data << endl;
}

int main() {
    vector<int> arr = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};

    Node* root = construct(arr);

    // Perform pre-order, post-order, and edge printing traversals
    traversals(root);

    // Clean up memory (not necessary in this simple example but good practice)
    // You would typically have a function to delete the tree
    return 0;
}
