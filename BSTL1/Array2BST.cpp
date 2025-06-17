#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int item) {
    Node* newNode = new Node;
    newNode->key = item;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Convert sorted array to balanced BST
Node* SortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* root = createNode(arr[mid]);

    root->left = SortedArrayToBST(arr, start, mid - 1);
    root->right = SortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Print tree level-wise
void printLevelWise(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = SortedArrayToBST(arr, 0, n - 1);
    cout << "Level order traversal of constructed BST:" << endl;
    printLevelWise(root);

    return 0;
}
