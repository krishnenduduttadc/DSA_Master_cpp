#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;

    Node(int val) {
        data = val;
    }
};

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

Node* getTail(Node* node) {
    while (node->children.size() == 1) {
        node = node->children[0];
    }
    return node;
}

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

int main() {
    vector<int> arr = {
        24, 10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, 110, -1, 120, -1, -1,
        90, -1, -1, 40, 100, -1, -1, -1
    };

    Node* root = construct(arr);
    linearize(root);
    display(root);

    return 0;
}
