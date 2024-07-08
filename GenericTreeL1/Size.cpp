#include <iostream>
#include <vector>
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

// Function to construct the tree from array representation
Node* construct(int arr[], int n) {
    Node* root = nullptr;
    vector<Node*> st;

    for (int i = 0; i < n; ++i) {
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

// Function to calculate the size of the tree
int size(Node* node) {
    int sz = 0;
    for (Node* child : node->children) {
        sz += size(child);
    }
    return 1 + sz;
}

int main() {
    // Static data representing the tree
    int arr[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Construct the tree
    Node* root = construct(arr, n);

    // Calculate the size of the tree
    int sz = size(root);
    cout << sz << endl;  // Output should be 6

    // Display the tree structure (optional)
    // display(root);

    return 0;
}
