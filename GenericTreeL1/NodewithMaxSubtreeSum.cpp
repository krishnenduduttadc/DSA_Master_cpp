#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

int msn = 0;
int ms = INT_MIN;

int retSumAndCalculateMSST(Node* node) {
    int sum = 0;

    for (Node* child : node->children) {
        int csum = retSumAndCalculateMSST(child);
        sum += csum;
    }

    sum += node->data;

    if (sum > ms) {
        msn = node->data;
        ms = sum;
    }

    return sum;
}

int main() {
    vector<int> arr = {20, 10, 20, -50, -1, 60, -1, -1, 30, -70, -1, 80, -1, 90, -1, -1, 40, -100, -1, -1, -1};

    Node* root = construct(arr);

    retSumAndCalculateMSST(root);
    cout << msn << "@" << ms << endl;
    return 0;
}
