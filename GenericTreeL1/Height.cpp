#include <iostream>
#include <vector>
#include <stack>

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

// Function to calculate the height of the tree
int height(Node* node) {
    if (node->children.empty()) {
        return 0;
    }

    int maxChildHeight = 0;
    for (Node* child : node->children) {
        int childHeight = height(child);
        if (childHeight > maxChildHeight) {
            maxChildHeight = childHeight;
        }
    }

    return maxChildHeight + 1;
}

// Main function
int main() {
    vector<int> arr = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};

    Node* root = construct(arr);
    int h = height(root);
    cout << h << endl;

    return 0;
}
