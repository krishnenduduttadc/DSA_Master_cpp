#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};

void elementsInRangeK1K2(Node* root, int k1, int k2) {
    if (root == nullptr)
        return;

    if (root->key > k1)
        elementsInRangeK1K2(root->left, k1, k2);

    if (root->key >= k1 && root->key <= k2)
        cout << root->key << " ";

    if (root->key < k2)
        elementsInRangeK1K2(root->right, k1, k2);
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << "Elements in range [5, 8]: ";
    elementsInRangeK1K2(root, 5, 8);
    cout << endl;

    return 0;
}
