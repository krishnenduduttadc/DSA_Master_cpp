#include <iostream>
#include <vector>
#include <stack>
#include <climits> // for INT_MAX and INT_MIN

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

int ceil_val = INT_MAX;
int floor_val = INT_MIN;

void ceilAndFloor(Node* node, int data) {
    if (!node) return;

    if (node->data > data) {
        if (node->data < ceil_val) {
            ceil_val = node->data;
        }
    }

    if (node->data < data) {
        if (node->data > floor_val) {
            floor_val = node->data;
        }
    }

    for (Node* child : node->children) {
        ceilAndFloor(child, data);
    }
}

int main() {
    vector<int> arr = {10, 20, -50, -1, 60, -1, -1, 30, 70, -1, -80, 110, -1, -120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    int data = 70;

    Node* root = construct(arr);
    ceil_val = INT_MAX;
    floor_val = INT_MIN;

    ceilAndFloor(root, data);

    cout << "CEIL = " << ceil_val << endl;
    cout << "FLOOR = " << floor_val << endl;

    return 0;
}
