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

// Variables to store the diameter of the tree
int dia = 0;

// Function to calculate the diameter and return the height of the subtree
int calculateDiaReturnHeight(Node* node) {
    int dch = -1; // deepest child height
    int sdch = -1; // second deepest child height

    for (Node* child : node->children) {
        int ch = calculateDiaReturnHeight(child);
        if (ch > dch) {
            sdch = dch;
            dch = ch;
        } else if (ch > sdch) {
            sdch = ch;
        }
    }

    // Update diameter if necessary
    if (dch + sdch + 2 > dia) {
        dia = dch + sdch + 2;
    }

    dch += 1; // height of current node
    return dch;
}

// Main function
int main() {
    vector<int> arr = {10, 20, -50, -1, 60, -1, -1, 30, -70, -1, 80, -1, 90, -1, -1, 40, -100, -1, -1, -1};

    Node* root = construct(arr);
    calculateDiaReturnHeight(root);

    cout << dia << endl;

    return 0;
}
