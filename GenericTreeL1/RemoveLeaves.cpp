#include <iostream>
#include <vector>
using namespace std;

// Node struct instead of class
struct Node {
    int data;
    vector<Node*> children;

    Node(int data) {
        this->data = data;
    }
};

// Display function
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

// Construct tree from array
Node* construct(int arr[], int n) {
    Node* root = nullptr;
    vector<Node*> st;

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            st.pop_back();
        } else {
            Node* t = new Node(arr[i]);

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

// Remove leaf nodes
void removeLeaves(Node* node) {
    for (int i = node->children.size() - 1; i >= 0; i--) {
        Node* child = node->children[i];
        if (child->children.empty()) {
            node->children.erase(node->children.begin() + i);
            delete child;
        }
    }

    for (Node* child : node->children) {
        removeLeaves(child);
    }
}

// Main function
int main() {
    int arr[] = {
        10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, 110, -1, 120, -1, -1,
        90, -1, -1, 40, 100, -1, -1, -1
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = construct(arr, n);
    removeLeaves(root);
    display(root);

    return 0;
}
