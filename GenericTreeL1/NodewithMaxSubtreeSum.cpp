#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

// Global variables to store the maximum subtree sum and its corresponding node value
int msn = 0;
int ms = INT_MIN;

// Function to recursively calculate the subtree sum and find the maximum subtree sum node
int retSumAndCalculateMSST(Node* node) {
    int sum = 0;

    for (Node* child : node->children) {
        int csum = retSumAndCalculateMSST(child);
        sum += csum;
    }

    sum += node->data;

    if (sum > ms) {
        msn = node->data;
        ms = sum;
    }

    return sum;
}

int main() {
    vector<int> arr = {20, 10, 20, -50, -1, 60, -1, -1, 30, -70, -1, 80, -1, 90, -1, -1, 40, -100, -1, -1, -1};

    Node* root = construct(arr);

    // Calculate the maximum subtree sum and corresponding node
    retSumAndCalculateMSST(root);

    // Print the result
    cout << msn << "@" << ms << endl;

    // Clean up memory (not necessary in this simple example but good practice)
    // You would typically have a function to delete the tree
    return 0;
}
