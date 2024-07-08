#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// Node class definition
class Node {
public:
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

// Function to find ceil and floor values of a given data in the tree
void ceilAndFloor(Node* node, int data, int& ceil, int& floor) {
    if (node->data > data) {
        if (node->data < ceil) {
            ceil = node->data;
        }
    }

    if (node->data < data) {
        if (node->data > floor) {
            floor = node->data;
        }
    }

    for (Node* child : node->children) {
        ceilAndFloor(child, data, ceil, floor);
    }
}

// Function to find the kth largest element in the tree
int kthLargest(Node* node, int k) {
    int floor = INT_MIN;
    int factor = INT_MAX;

    for (int i = 0; i < k; ++i) {
        ceilAndFloor(node, factor, factor, floor);
        floor = INT_MIN;
    }

    return factor;
}

// Main function
int main() {
    vector<int> arr = {24, 10, 20, -50, -1, 60, -1, -1, 30, 70, -1, -80, 110, -1, -120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    int k = 8;

    Node* root = construct(arr);
    int kthLargestValue = kthLargest(root, k);
    cout << kthLargestValue << endl;

    return 0;
}
