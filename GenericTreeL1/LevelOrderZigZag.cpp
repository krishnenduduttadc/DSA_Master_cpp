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

void levelOrderLinewiseZZ(Node* root) {
    if (!root) return;

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;
    int level = 1;

    currentLevel.push(root);

    while (!currentLevel.empty()) {
        Node* node = currentLevel.top();
        currentLevel.pop();

        cout << node->data << " ";

        if (level % 2 == 1) {
            for (Node* child : node->children)
                nextLevel.push(child);
        } else {
            for (int i = node->children.size() - 1; i >= 0; --i)
                nextLevel.push(node->children[i]);
        }

        if (currentLevel.empty()) {
            cout << endl;
            swap(currentLevel, nextLevel);
            level++;
        }
    }
}

int main() {
    vector<int> arr = {
        24, 10, 20, 50, -1, 60, -1, -1,
        30, 70, -1, 80, 110, -1, 120, -1,
        -1, 90, -1, -1, 40, 100, -1, -1, -1
    };

    Node* root = construct(arr);
    levelOrderLinewiseZZ(root);

    return 0;
}
