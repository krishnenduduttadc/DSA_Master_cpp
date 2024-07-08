#include <iostream>
#include <vector>
#include <queue>
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

// Function for level order traversal
void levelOrder(Node* node) {
    if (!node)
        return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        cout << f->data << " ";

        for (Node* child : f->children) {
            q.push(child);
        }
    }
    cout << "." << endl;
}

// Main function
int main() {
    vector<int> arr = {24, 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node* root = construct(arr);
    levelOrder(root);

    return 0;
}
