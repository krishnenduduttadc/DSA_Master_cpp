#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int size(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int ls = size(node->left);
    int rs = size(node->right);
    return ls + rs + 1;
}

int sum(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int ls = sum(node->left);
    int rs = sum(node->right);
    return ls + rs + node->data;
}

int max(Node *node)
{
    if (node->right != nullptr)
    {
        return max(node->right);
    }
    else
    {
        return node->data;
    }
}

int min(Node *node)
{
    if (node->left != nullptr)
    {
        return min(node->left);
    }
    else
    {
        return node->data;
    }
}

bool find(Node *node, int data)
{
    if (node == nullptr)
    {
        return false;
    }
    if (data > node->data)
    {
        return find(node->right, data);
    }
    else if (data < node->data)
    {
        return find(node->left, data);
    }
    else
    {
        return true;
    }
}

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << (node->left ? to_string(node->left->data) : ".") << " <- " << node->data << " -> " << (node->right ? to_string(node->right->data) : ".") << endl;
    display(node->left);
    display(node->right);
}

int main()
{
    Node *node12 = new Node(12);
    Node *node30 = new Node(30);
    Node *node37 = new Node(37, node30);
    Node *node62 = new Node(62);
    Node *node87 = new Node(87);
    Node *node25 = new Node(25, node12, node37);
    Node *node75 = new Node(75, node62, node87);
    Node *root = new Node(50, node25, node75);

    int sizeOfTree = size(root);
    int sumOfTree = sum(root);
    int maxValue = max(root);
    int minValue = min(root);
    int dataToFind = 6;
    bool isFound = find(root, dataToFind);

    cout << "Size of BST: " << sizeOfTree << endl;
    cout << "Sum of BST: " << sumOfTree << endl;
    cout << "Maximum value in BST: " << maxValue << endl;
    cout << "Minimum value in BST: " << minValue << endl;
    cout << "Is " << dataToFind << " found in BST? " << (isFound ? "Yes" : "No") << endl;

    cout << "BST Structure:" << endl;
    display(root);

    return 0;
}
