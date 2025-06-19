#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

void levelWise(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        cout << front->data << " ";

        if (front->left != nullptr)
            q.push(front->left);
        if (front->right != nullptr)
            q.push(front->right);
    }
}

void printLevelWise(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* front = q.front();
            q.pop();
            cout << front->data << " ";

            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
        cout << endl;
    }
}

void printLeftView(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* front = q.front();
            q.pop();

            if (i == 0)
                cout << front->data << " ";

            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
        cout << endl;
    }
}

// Function to print right view of the tree
void printRightView(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* front = q.front();
            q.pop();

            if (i == size - 1)
                cout << front->data << " ";

            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
        cout << endl;
    }
}

// Function to perform pre-order traversal
void preOrder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // Hardcoded tree construction
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    // Demonstrate each operation
    cout << "Level-wise traversal:" << endl;
    levelWise(root);
    cout << endl << endl;

    cout << "Level-wise printing:" << endl;
    printLevelWise(root);
    cout << endl;

    cout << "Left view of the tree:" << endl;
    printLeftView(root);
    cout << endl;

    cout << "Right view of the tree:" << endl;
    printRightView(root);
    cout << endl;

    cout << "Pre-order traversal:" << endl;
    preOrder(root);
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
