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

// Function to find if a node with given data exists in the tree
bool find(Node* node, int data) {
    if (node->data == data) {
        return true;
    }

    for (Node* child : node->children) {
        if (find(child, data)) {
            return true;
        }
    }

    return false;
}

// Main function
int main() {
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int data = 120; // Data of the node to search for

    Node* root = construct(arr);
    bool flag = find(root, data);
    cout << boolalpha << flag << endl;

    return 0;
}
