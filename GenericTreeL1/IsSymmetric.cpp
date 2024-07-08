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

// Function to check if two trees are mirrors of each other
bool areMirror(Node* n1, Node* n2) {
    if (n1->children.size() != n2->children.size()) {
        return false;
    }

    for (int i = 0; i < n1->children.size(); ++i) {
        int j = n1->children.size() - 1 - i;
        Node* c1 = n1->children[i];
        Node* c2 = n2->children[j];

        if (!areMirror(c1, c2)) {
            return false;
        }
    }

    return true;
}

// Function to check if a tree is symmetric
bool IsSymmetric(Node* node) {
    return areMirror(node, node);
}

// Main function
int main() {
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, -1, 90, -1, -1, 40, 100, -1, 110, -1, -1, -1};

    Node* root = construct(arr);
    bool sym = IsSymmetric(root);
    cout << boolalpha << sym << endl;

    return 0;
}
