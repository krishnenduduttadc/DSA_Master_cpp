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

// Function to display the tree
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

// Function to get the tail of a node
Node* getTail(Node* node) {
    while (node->children.size() == 1) {
        node = node->children[0];
    }
    return node;
}

// Function to linearize the tree
void linearize(Node* node) {
    for (Node* child : node->children) {
        linearize(child);
    }

    while (node->children.size() > 1) {
        Node* lastChild = node->children.back();
        node->children.pop_back();
        Node* secondLastChild = node->children.back();
        Node* tail = getTail(secondLastChild);
        tail->children.push_back(lastChild);
    }
}

// Main function
int main() {
    vector<int> arr = {24, 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    
    Node* root = construct(arr);
    linearize(root);
    display(root);

    return 0;
}
