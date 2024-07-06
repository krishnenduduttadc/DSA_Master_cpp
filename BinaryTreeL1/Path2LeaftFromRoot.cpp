#include <iostream>
#include <string>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {}
};

// Function to print paths from root to leaf nodes with sum within range [lo, hi]
void pathToLeafFromRoot(Node* node, string path, int sum, int lo, int hi) {
    if (node == nullptr)
        return;

    // Include current node in the path and add its data to sum
    path += to_string(node->data) + " ";
    sum += node->data;

    // If leaf node is reached, check if sum is within range [lo, hi] and print path
    if (node->left == nullptr && node->right == nullptr) {
        if (sum >= lo && sum <= hi) {
            cout << path << endl;
        }
        return;
    }

    // Recursively traverse left and right subtrees
    pathToLeafFromRoot(node->left, path, sum, lo, hi);
    pathToLeafFromRoot(node->right, path, sum, lo, hi);
}

int main() {
    // Hardcoded values for lo and hi
    int lo = 150;
    int hi = 250;

    // Hardcoded tree construction
    Node* root = new Node(50,
                          new Node(25,
                                   new Node(12, nullptr, nullptr),
                                   new Node(37,
                                            new Node(30, nullptr, nullptr),
                                            new Node(40, nullptr, nullptr))),
                          new Node(75,
                                   new Node(62,
                                            new Node(60, nullptr, nullptr),
                                            new Node(70, nullptr, nullptr)),
                                   new Node(87, nullptr, nullptr)));

    // Call function to find paths from root to leaf nodes with sum in range [lo, hi]
    pathToLeafFromRoot(root, "", 0, lo, hi);

    // Clean up dynamically allocated memory
    delete root->right->left->right;
    delete root->right->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
