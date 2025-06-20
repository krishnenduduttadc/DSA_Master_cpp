#include <iostream>
#include <vector>
#include <stack>
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

void traversals(Node* node) {
    cout << "Node Pre " << node->data << endl;

    for (Node* child : node->children) {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traversals(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }

    cout << "Node Post " << node->data << endl;
}

int main() {
    vector<int> arr = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    Node* root = construct(arr);
    traversals(root);
    return 0;
}
