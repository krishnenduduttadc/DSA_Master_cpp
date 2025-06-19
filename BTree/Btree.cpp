#include <iostream>
using namespace std;

struct BTreeNode {
    int *keys;
    BTreeNode **C;
    int t;
    int n;
    bool leaf;
};

BTreeNode* createNode(int t, bool leaf);
void traverse(BTreeNode* root);
BTreeNode* search(BTreeNode* root, int k);
void insert(int k);
void insertNonFull(BTreeNode* node, int k);
void splitChild(BTreeNode* parent, int i, BTreeNode* child);
void splitRoot();

BTreeNode* root = nullptr;
int t_global;

BTreeNode* createNode(int t, bool leaf) {
    BTreeNode* node = new BTreeNode;
    node->t = t;
    node->leaf = leaf;
    node->n = 0;
    node->keys = new int[2 * t - 1];
    node->C = new BTreeNode*[2 * t];
    return node;
}

void traverse(BTreeNode* node) {
    if (!node) return;

    int i;
    for (i = 0; i < node->n; i++) {
        if (!node->leaf) traverse(node->C[i]);
        cout << node->keys[i] << " ";
    }
    if (!node->leaf) traverse(node->C[i]);
}

BTreeNode* search(BTreeNode* node, int k) {
    int i = 0;
    while (i < node->n && k > node->keys[i]) i++;

    if (i < node->n && node->keys[i] == k) return node;
    if (node->leaf) return nullptr;

    return search(node->C[i], k);
}

void insert(int k) {
    if (root == nullptr) {
        root = createNode(t_global, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t_global - 1) {
            splitRoot();
        }
        insertNonFull(root, k);
    }
}

void splitRoot() {
    BTreeNode* s = createNode(t_global, false);
    s->C[0] = root;
    splitChild(s, 0, root);
    root = s;
}

void insertNonFull(BTreeNode* node, int k) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && node->keys[i] > k) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = k;
        node->n++;
    } else {
        while (i >= 0 && node->keys[i] > k) i--;
        if (node->C[i + 1]->n == 2 * node->t - 1) {
            splitChild(node, i + 1, node->C[i + 1]);
            if (node->keys[i + 1] < k) i++;
        }
        insertNonFull(node->C[i + 1], k);
    }
}

void splitChild(BTreeNode* parent, int i, BTreeNode* y) {
    BTreeNode* z = createNode(y->t, y->leaf);
    z->n = y->t - 1;

    for (int j = 0; j < y->t - 1; j++)
        z->keys[j] = y->keys[j + y->t];

    if (!y->leaf) {
        for (int j = 0; j < y->t; j++)
            z->C[j] = y->C[j + y->t];
    }

    y->n = y->t - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->C[j + 1] = parent->C[j];

    parent->C[i + 1] = z;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = y->keys[y->t - 1];
    parent->n++;
}

int main() {
    t_global = 3; // Set minimum degree

    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(12);
    insert(30);
    insert(7);
    insert(17);

    cout << "B-tree traversal: ";
    traverse(root);

    int key = 6;
    if (search(root, key))
        cout << "\nKey " << key << " is present" << endl;
    else
        cout << "\nKey " << key << " is not present" << endl;

    return 0;
}
