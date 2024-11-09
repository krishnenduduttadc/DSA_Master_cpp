#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key, lcount;
    Node *left, *right;

    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
        lcount = 0;
    }
};

Node* insertRec(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insertRec(root->left, key);
        root->lcount++;
    }
    if (key > root->key) {
        root->right = insertRec(root->right, key);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

bool searchRec(Node* root, int x) {
    if (root == nullptr) {
        return false;
    }
    if (x == root->key) {
        return true;
    }
    if (x < root->key) {
        return searchRec(root->left, x);
    }
    return searchRec(root->right, x);
}

bool searchIterative(Node* root, int x) {
    Node* curr = root;
    while (curr != nullptr) {
        if (x == curr->key) {
            return true;
        }
        if (x < curr->key) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return false;
}

Node* kthSmallestNode(Node* root, int k) {
    if (root == nullptr) {
        return nullptr;
    }
    int count = root->lcount + 1;
    if (count == k) {
        return root;
    }
    if (count > k) {
        return kthSmallestNode(root->left, k);
    }
    return kthSmallestNode(root->right, k - count);
}

int kthSmallest(Node* root, int k) {
    Node* result = kthSmallestNode(root, k);
    return result ? result->key : -1;
}

Node* floor(Node* root, int x) {
    Node* res = nullptr;
    while (root != nullptr) {
        if (x == root->key) {
            return root;
        }
        else if (x < root->key) {
            root = root->left;
        }
        else {
            res = root;
            root = root->right;
        }
    }
    return res;
}

Node* ceiling(Node* root, int x) {
    Node* res = nullptr;
    while (root != nullptr) {
        if (x == root->key) {
            return root;
        }
        else if (x < root->key) {
            res = root;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return res;
}

int floorValue(Node* root, int x) {
    Node* result = floor(root, x);
    return result ? result->key : -1;
}

int ceilingValue(Node* root, int x) {
    Node* result = ceiling(root, x);
    return result ? result->key : -1;
}

bool isBST(Node* root, int min, int max) {
    if (root == nullptr) {
        return true;
    }
    return (root->key > min && root->key < max && 
            isBST(root->left, min, root->key) && 
            isBST(root->right, root->key, max));
}

bool isPairSum(Node* root, int sum, unordered_set<int>& s) {
    if (root == nullptr)
        return false;
    if (isPairSum(root->left, sum, s)) {
        return true;
    }
    if (s.find(sum - root->key) != s.end()) {
        return true;
    }
    s.insert(root->key);
    return isPairSum(root->right, sum, s);
}

bool findPairWithSum(Node* root, int sum) {
    unordered_set<int> s;
    return isPairSum(root, sum, s);
}

int main() {
    Node* root = nullptr;
    
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i : data) {
        root = insertRec(root, i);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    cout << "80 present? " << (searchRec(root, 80) ? "Yes" : "No") << "\n";
    cout << "90 present? " << (searchRec(root, 90) ? "Yes" : "No") << "\n";

    cout << "81 present? " << (searchIterative(root, 81) ? "Yes" : "No") << "\n";
    cout << "Is BST? " << (isBST(root, INT_MIN, INT_MAX) ? "Yes" : "No") << "\n";

    cout << "Floor of 58? " << floorValue(root, 58) << "\n";
    cout << "Ceiling of 58? " << ceilingValue(root, 58) << "\n";

    cout << "4th smallest element? " << kthSmallest(root, 4) << "\n";

    cout << "Pair with sum 70? " << (findPairWithSum(root, 70) ? "Yes" : "No") << "\n";

    return 0;
}