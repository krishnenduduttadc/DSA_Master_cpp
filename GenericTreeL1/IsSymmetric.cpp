#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
    Node(int val)  {data=val;}
};

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

bool IsSymmetric(Node* node) {
    return areMirror(node, node);
}

int main() {
    vector<int> arr = {
        10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, -1, 90, -1, -1,
        40, 100, -1, 110, -1, -1, -1
    };

    Node* root = construct(arr);
    cout << boolalpha << IsSymmetric(root) << endl;

    return 0;
}
