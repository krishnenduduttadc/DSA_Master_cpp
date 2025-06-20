#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    vector<Node*> children;
};

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

int size(Node* node) {
    int sz = 0;
    for (Node* child : node->children) {
        sz += size(child);
    }
    return 1 + sz;
}

int main() {
    int arr[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = construct(arr, n);

    int sz = size(root);
    cout << sz << endl;  // Output should be 6
    return 0;
}
