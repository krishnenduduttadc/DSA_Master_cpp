#include <iostream>
using namespace std;

class BTree {
private:
    struct BTreeNode {
        int *keys;      // Array to hold keys
        BTreeNode **C;  // Array to hold child pointers
        int t;          // Minimum degree (defines range for keys)
        int n;          // Number of keys in the node
        bool leaf;      // True if the node is a leaf

        BTreeNode(int t, bool leaf);   // Constructor for BTreeNode

        void traverse();               // Function to traverse all nodes
        BTreeNode* search(int k);      // Search key in the subtree
        void insertNonFull(int k);     // Insert when node is not full
        void splitChild(int i, BTreeNode* y);  // Split a child node
    };

    BTreeNode* root;  // Pointer to the root node
    int t;            // Minimum degree

    void splitRoot();  // Split the root if it's full

public:
    BTree(int t);      // Constructor for BTree

    void insert(int k);  // Function to insert a key
    void traverse();     // Function to traverse the B-tree
    bool search(int k);  // Function to search for a key
};

// Constructor for BTreeNode
BTree::BTreeNode::BTreeNode(int t, bool leaf) {
    this->t = t;
    this->leaf = leaf;
    keys = new int[2 * t - 1];  // Maximum 2*t-1 keys
    C = new BTreeNode*[2 * t];  // Maximum 2*t children
    n = 0;  // Initially no keys
}

// Function to traverse the B-tree and print keys
void BTree::BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) C[i]->traverse();  // Traverse child first if not leaf
        cout << keys[i] << " ";       // Print key
    }
    if (!leaf) C[i]->traverse();      // Traverse last child
}

// Function to search for a key in the subtree rooted at this node
BTree::BTreeNode* BTree::BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i]) i++;  // Find the first key >= k

    if (keys[i] == k) return this;     // If key found, return this node
    if (leaf) return nullptr;          // If leaf, return nullptr

    return C[i]->search(k);            // Recur to appropriate child
}

// Function to insert a key in a non-full node
void BTree::BTreeNode::insertNonFull(int k) {
    int i = n - 1;  // Initialize index of the rightmost key

    if (leaf) {  // If this is a leaf node
        while (i >= 0 && keys[i] > k) {  // Find the correct location
            keys[i + 1] = keys[i];  // Shift keys to the right
            i--;
        }
        keys[i + 1] = k;  // Insert the new key
        n++;  // Increment the number of keys
    } else {  // If this is not a leaf node
        while (i >= 0 && keys[i] > k) i--;  // Find the child to insert into

        if (C[i + 1]->n == 2 * t - 1) {  // If the child is full
            splitChild(i + 1, C[i + 1]);  // Split the child

            if (keys[i + 1] < k) i++;  // Adjust index if needed after splitting
        }
        C[i + 1]->insertNonFull(k);  // Recur on the appropriate child
    }
}

// Function to split a child node when it is full
void BTree::BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);  // Create a new node
    z->n = t - 1;  // New node will have t-1 keys

    for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];  // Copy last t-1 keys of y to z

    if (!y->leaf) {  // If y is not a leaf, copy its children to z
        for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
    }

    y->n = t - 1;  // Reduce the number of keys in y

    for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];  // Shift child pointers
    C[i + 1] = z;  // Link the new child

    for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];  // Shift keys in this node
    keys[i] = y->keys[t - 1];  // Move the middle key to this node

    n++;  // Increment the number of keys
}

// BTree constructor
BTree::BTree(int t) {
    root = nullptr;
    this->t = t;
}

// Function to handle root splitting when it's full
void BTree::splitRoot() {
    BTreeNode* s = new BTreeNode(t, false);  // Create a new node to be the root
    s->C[0] = root;  // Old root becomes the child of the new root
    s->splitChild(0, root);  // Split the old root
    root = s;  // Update the root
}

// Insert function to insert a new key into the B-tree
void BTree::insert(int k) {
    if (root == nullptr) {  // If the tree is empty, create the root
        root = new BTreeNode(t, true);
        root->keys[0] = k;  // Insert the first key
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {  // If the root is full
            splitRoot();  // Split the root
        }
        root->insertNonFull(k);  // Insert the key into the non-full root
    }
}

// Function to traverse the B-tree and print keys
void BTree::traverse() {
    if (root != nullptr) root->traverse();
}

// Function to search for a key in the B-tree
bool BTree::search(int k) {
    return (root == nullptr) ? false : (root->search(k) != nullptr);
}

// Main function to test the B-tree
int main() {
    BTree t(3);  // Create a B-tree with minimum degree 3

    // Insert some keys
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    // Print the B-tree
    cout << "B-tree traversal: ";
    t.traverse();

    // Search for a key
    int key = 6;
    if (t.search(key))
        cout << "\nKey " << key << " is present" << endl;
    else
        cout << "\nKey " << key << " is not present" << endl;

    return 0;
}
