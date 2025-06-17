#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// Node structure definition
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

// Function to find ceil and floor values of a given data in the tree
void ceilAndFloor(Node* node, int data, int& ceil, int& floor) {
    if (node->data > data && node->data < ceil) {
        ceil = node->data;
    }
    if (node->data < data && node->data > floor) {
        floor = node->data;
    }

    for (Node* child : node->children) {
        ceilAndFloor(child, data, ceil, floor);
    }
}

// Function to find the kth largest element in the tree
int kthLargest(Node* node, int k) {
    int factor = INT_MAX;
    int floor;

    for (int i = 0; i < k; ++i) {
        floor = INT_MIN;
        ceilAndFloor(node, factor, factor, floor);
        factor = floor;
    }

    return factor;
}

// Main function
int main() {
    vector<int> arr = {
        24, 10, 20, -50, -1, 60, -1, -1, 30,
        70, -1, -80, 110, -1, -120, -1, -1,
        90, -1, -1, 40, -100, -1, -1, -1
    };
    int k = 8;

    Node* root = construct(arr);
    int kthLargestValue = kthLargest(root, k);
    cout << kthLargestValue << endl;

    return 0;
}
