#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// Definition of a binary tree node
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Class to store results of isBST function
class BSTPair
{
public:
    bool isBST;
    int min;
    int max;
    BSTPair(bool isBST = true, int min = INT_MAX, int max = INT_MIN)
    {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
    }

    // BSTPair(bool isBST = true, int min = INT_MAX, int max = INT_MIN) : isBST(isBST), min(min), max(max) {}
};

// Function to display the binary tree (preorder traversal)
void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = "";
    str += (node->left == nullptr ? "." : to_string(node->left->data)) + " <- " + to_string(node->data) + " -> ";
    str += (node->right == nullptr ? "." : to_string(node->right->data));
    cout << str << endl;

    display(node->left);
    display(node->right);
}

// Function to calculate the height of the tree
int height(Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }

    int lh = height(node->left);
    int rh = height(node->right);

    return max(lh, rh) + 1;
}

// Function to check if a subtree rooted at 'node' is a BST
BSTPair isBST(Node *node)
{
    if (node == nullptr)
    {
        return BSTPair(true, INT_MAX, INT_MIN);
    }

    BSTPair lp = isBST(node->left);
    BSTPair rp = isBST(node->right);

    BSTPair mp;
    mp.isBST = lp.isBST && rp.isBST && (node->data >= lp.max && node->data <= rp.min);
    mp.min = min(node->data, min(lp.min, rp.min));
    mp.max = max(node->data, max(lp.max, rp.max));

    return mp;
}

int main()
{
    // Hardcoded tree construction
    Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);

    root->left->left = new Node(12);
    root->left->right = new Node(37);

    root->right->left = new Node(62);
    root->right->right = new Node(87);

    // Check if the tree is a BST
    BSTPair bp = isBST(root);
    cout << "Is the tree a BST? " << (bp.isBST ? "Yes" : "No") << endl;

    return 0;
}
