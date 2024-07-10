#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <climits>

class Node {
public:
    int key;
    Node *left, *right;

     Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;    
    }
};

class BST {
private:
    Node* root;
    int maxlevel = 0;
    int dia = 0;

public:
    BST() : root(nullptr) {}

    void Inorder(Node* root) {
        if (root == nullptr) return;
        Inorder(root->left);
        std::cout << root->key << " ";
        Inorder(root->right);
    }

    Node* insert(Node* root, int x) {
        if (root == nullptr) return new Node(x);
        if (x < root->key)
            root->left = insert(root->left, x);
        else if (x > root->key)
            root->right = insert(root->right, x);
        return root;
    }

    bool search(Node* root, int x) {
        if (root == nullptr) return false;
        if (root->key == x) return true;
        return (x < root->key) ? search(root->left, x) : search(root->right, x);
    }

    bool isPairSum(Node* root, int sum, std::unordered_set<int>& s) {
        if (root == nullptr) return false;
        if (isPairSum(root->left, sum, s)) return true;
        if (s.find(sum - root->key) != s.end()) return true;
        s.insert(root->key);
        return isPairSum(root->right, sum, s);
    }

    int height(Node* root) {
        if (root == nullptr) return 0;
        return 1 + std::max(height(root->left), height(root->right));
    }

    void nodeatdistK(Node* root, int k) {
        if (root == nullptr) return;
        if (k == 0) std::cout << root->key << " ";
        else {
            nodeatdistK(root->left, k - 1);
            nodeatdistK(root->right, k - 1);
        }
    }

    void levelOrder(Node* root) {
        if (root == nullptr) return;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            std::cout << curr->key << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    void levelOrderLineByLine(Node* root) {
        if (root == nullptr) return;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                std::cout << curr->key << " ";
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            std::cout << std::endl;
        }
    }

    int size(Node* root) {
        if (root == nullptr) return 0;
        return 1 + size(root->left) + size(root->right);
    }

    int getMax(Node* root) {
        if (root == nullptr) return INT_MIN;
        return std::max(root->key, std::max(getMax(root->left), getMax(root->right)));
    }

    void printLeftRecursive(Node* root, int level) {
        if (root == nullptr) return;
        if (maxlevel < level) {
            std::cout << root->key << std::endl;
            maxlevel = level;
        }
        printLeftRecursive(root->left, level + 1);
        printLeftRecursive(root->right, level + 1);
    }

    void printLeftIterative(Node* root) {
        if (root == nullptr) return;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (i == 0) std::cout << curr->key << " ";
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            std::cout << std::endl;
        }
    }

    bool childrenSum(Node* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        int sum = 0;
        if (root->left) sum += root->left->key;
        if (root->right) sum += root->right->key;
        return (root->key == sum && childrenSum(root->left) && childrenSum(root->right));
    }

    bool isBalanced(Node* root) {
        if (root == nullptr) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        return (std::abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }

    int maxWidth(Node* root) {
        if (root == nullptr) return 0;
        std::queue<Node*> q;
        q.push(root);
        int maxWidth = 0;
        while (!q.empty()) {
            int size = q.size();
            maxWidth = std::max(maxWidth, size);
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return maxWidth;
    }

    void printSpiral(Node* root) {
        if (root == nullptr) return;
        std::queue<Node*> q;
        std::stack<int> s;
        bool reverse = false;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (reverse)
                    s.push(curr->key);
                else
                    std::cout << curr->key << " ";
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (reverse) {
                while (!s.empty()) {
                    std::cout << s.top() << " ";
                    s.pop();
                }
            }
            reverse = !reverse;
            std::cout << std::endl;
        }
    }

    int diameter(Node* root) {
        if (root == nullptr) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        dia = std::max(dia, 1 + lh + rh);
        return 1 + std::max(lh, rh);
    }

    // Public interface methods
    void insert(int x) { root = insert(root, x); }
    void inorder() { Inorder(root); }
    bool search(int x) { return search(root, x); }
    bool isPairSum(int sum) {
        std::unordered_set<int> s;
        return isPairSum(root, sum, s);
    }
    int getHeight() { return height(root); }
    int getSize() { return size(root); }
    int getDiameter() { diameter(root); return dia; }
    int getMaximum() { return getMax(root); }
    bool isBalanced() { return isBalanced(root); }
    void printNodesAtDistanceK(int k) { nodeatdistK(root, k); }
    void printLevelOrder() { levelOrder(root); }
    void printLevelOrderLineByLine() { levelOrderLineByLine(root); }
    void printLeftView() { printLeftRecursive(root, 1); }
    void printLeftViewIterative() { printLeftIterative(root); }
    bool hasChildrenSum() { return childrenSum(root); }
    int getMaxWidth() { return maxWidth(root); }
    void printSpiralOrder() { printSpiral(root); }
};

int main() {
    BST tree;

    tree.insert(10);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder traversal: ";
    tree.inorder();
    std::cout << std::endl;

    std::cout << "Item found: " << (tree.search(70) ? "Yes" : "No") << std::endl;
    std::cout << "Pair sum exists: " << (tree.isPairSum(51) ? "Yes" : "No") << std::endl;
    std::cout << "Height is: " << tree.getHeight() << std::endl;
    std::cout << "Size is: " << tree.getSize() << std::endl;
    std::cout << "Diameter is: " << tree.getDiameter() << std::endl;
    std::cout << "Maximum is: " << tree.getMaximum() << std::endl;
    std::cout << "Is tree balanced: " << (tree.isBalanced() ? "Yes" : "No") << std::endl;

    std::cout << "Nodes at distance 2: ";
    tree.printNodesAtDistanceK(2);
    std::cout << std::endl;

    std::cout << "Level order traversal: ";
    tree.printLevelOrder();
    std::cout << std::endl;

    std::cout << "Level order line by line:" << std::endl;
    tree.printLevelOrderLineByLine();

    std::cout << "Spiral order:" << std::endl;
    tree.printSpiralOrder();

    std::cout << "Left view:" << std::endl;
    tree.printLeftView();

    std::cout << "Left view (iterative):" << std::endl;
    tree.printLeftViewIterative();

    std::cout << "Children sum property holds: " << (tree.hasChildrenSum() ? "Yes" : "No") << std::endl;
    std::cout << "Width of tree is: " << tree.getMaxWidth() << std::endl;

    return 0;
}