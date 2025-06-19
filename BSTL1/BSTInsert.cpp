#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <climits>
#include <cmath>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

bool search(Node* root, int x) {
    if (root == nullptr) return false;
    if (root->key == x) return true;
    return (x < root->key) ? search(root->left, x) : search(root->right, x);
}

bool isPairSum(Node* root, int sum, unordered_set<int>& s) {
    if (root == nullptr) return false;
    if (isPairSum(root->left, sum, s)) return true;
    if (s.count(sum - root->key)) return true;
    s.insert(root->key);
    return isPairSum(root->right, sum, s);
}

int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int size(Node* root) {
    if (root == nullptr) return 0;
    return 1 + size(root->left) + size(root->right);
}

int getMax(Node* root) {
    if (root == nullptr) return INT_MIN;
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}

bool isBalanced(Node* root) {
    if (root == nullptr) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

bool childrenSum(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;
    int sum = 0;
    if (root->left) sum += root->left->key;
    if (root->right) sum += root->right->key;
    return (root->key == sum && childrenSum(root->left) && childrenSum(root->right));
}

void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

void levelOrderLineByLine(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

void printNodesAtDistanceK(Node* root, int k) {
    if (root == nullptr) return;
    if (k == 0) cout << root->key << " ";
    else {
        printNodesAtDistanceK(root->left, k - 1);
        printNodesAtDistanceK(root->right, k - 1);
    }
}

int diameterUtil(Node* root, int& dia) {
    if (root == nullptr) return 0;
    int lh = diameterUtil(root->left, dia);
    int rh = diameterUtil(root->right, dia);
    dia = max(dia, 1 + lh + rh);
    return 1 + max(lh, rh);
}

int diameter(Node* root) {
    int dia = 0;
    diameterUtil(root, dia);
    return dia;
}

int maxWidth(Node* root) {
    if (root == nullptr) return 0;
    queue<Node*> q;
    q.push(root);
    int maxW = 0;
    while (!q.empty()) {
        int width = q.size();
        maxW = max(maxW, width);
        for (int i = 0; i < width; i++) {
            Node* curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return maxW;
}

void printSpiral(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* curr = s1.top(); s1.pop();
            cout << curr->key << " ";
            if (curr->right) s2.push(curr->right);
            if (curr->left) s2.push(curr->left);
        }
        while (!s2.empty()) {
            Node* curr = s2.top(); s2.pop();
            cout << curr->key << " ";
            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }
    }
}

void printLeftView(Node* root, int level, int& maxLevel) {
    if (root == nullptr) return;
    if (level > maxLevel) {
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeftView(root->left, level + 1, maxLevel);
    printLeftView(root->right, level + 1, maxLevel);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Search 70: " << (search(root, 70) ? "Yes" : "No") << "\n";

    unordered_set<int> s;
    cout << "Pair sum 51 exists: " << (isPairSum(root, 51, s) ? "Yes" : "No") << "\n";

    cout << "Height: " << height(root) << "\n";
    cout << "Size: " << size(root) << "\n";
    cout << "Diameter: " << diameter(root) << "\n";
    cout << "Maximum: " << getMax(root) << "\n";
    cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << "\n";
    cout << "Children Sum Property: " << (childrenSum(root) ? "Yes" : "No") << "\n";

    cout << "Nodes at Distance 2: ";
    printNodesAtDistanceK(root, 2);
    cout << "\n";

    cout << "Level Order: ";
    levelOrder(root);
    cout << "\n";

    cout << "Level Order Line by Line:\n";
    levelOrderLineByLine(root);

    cout << "Spiral Order: ";
    printSpiral(root);
    cout << "\n";

    cout << "Left View: ";
    int maxLevel = 0;
    printLeftView(root, 1, maxLevel);
    cout << "\n";

    cout << "Maximum Width: " << maxWidth(root) << "\n";

    return 0;
}
