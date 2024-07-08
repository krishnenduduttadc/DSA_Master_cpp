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

// Function for level order traversal in zigzag manner
void levelOrderLinewiseZZ(Node* node) {
    if (!node)
        return;

    stack<Node*> ms;  // Main stack
    stack<Node*> cs;  // Children stack
    int level = 1;

    ms.push(node);

    while (!ms.empty()) {
        node = ms.top();
        ms.pop();

        cout << node->data << " ";

        // Determine the order of pushing children based on level
        if (level % 2 == 1) { // Odd level: left to right
            for (int i = 0; i < node->children.size(); ++i) {
                cs.push(node->children[i]);
            }
        } else { // Even level: right to left
            for (int i = node->children.size() - 1; i >= 0; --i) {
                cs.push(node->children[i]);
            }
        }

        // If main stack is empty, switch to children stack for next level
        if (ms.empty()) {
            ms = cs;
            while (!cs.empty()) {
                cs.pop();
            }
            level++;
            cout << endl;
        }
    }
}

// Main function
int main() {
    vector<int> arr = {24, 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node* root = construct(arr);
    levelOrderLinewiseZZ(root);

    return 0;
}
