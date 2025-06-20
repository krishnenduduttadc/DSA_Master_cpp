#include <iostream>
#include <vector>
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

Node* construct(int arr[], int n) {
    Node* root = nullptr;
    vector<Node*> st;

    for (int i = 0; i < n; ++i) {
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

bool areSimilar(Node* n1, Node* n2) {
    if (n1->children.size() != n2->children.size()) {
        return false;
    }

    for (size_t i = 0; i < n1->children.size(); ++i) {
        if (!areSimilar(n1->children[i], n2->children[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr1[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node* root1 = construct(arr1, n1);

    int arr2[] = {1, 2, 5, -1, 6, -1, -1, 3, 7, -1, 8, 11, -1, 12, -1, -1, 9, -1, -1, 4, 10, -1, -1, -1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node* root2 = construct(arr2, n2);

    bool similar = areSimilar(root1, root2);

    cout << boolalpha << similar << endl;  // Output should be false for the given trees

    return 0;
}
