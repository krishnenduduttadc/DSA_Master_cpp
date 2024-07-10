#include <iostream>
using namespace std;

class BSTFloorCeil
{
public:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int item)
        {
            data = item;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;

    Node *Floor(Node *node, int x)
    {
        Node *res = nullptr;
        while (node != nullptr)
        {
            if (node->data == x)
            {
                return node;
            }
            if (node->data > x)
            {
                node = node->left;
            }
            else
            {
                res = node;
                node = node->right;
            }
        }
        return res;
    }

    int Ceil(Node *node, int x)
    {
        if (node == nullptr)
        {
            return -1;
        }
        if (node->data == x)
        {
            return node->data;
        }
        if (node->data < x)
        {
            return Ceil(node->right, x);
        }
        int ceil = Ceil(node->left, x);
        return (ceil >= x) ? ceil : node->data;
    }
};

int main()
{
    BSTFloorCeil tree;

    // Construct the BST
    tree.root = new BSTFloorCeil::Node(8);
    tree.root->left = new BSTFloorCeil::Node(4);
    tree.root->right = new BSTFloorCeil::Node(12);
    tree.root->left->left = new BSTFloorCeil::Node(2);
    tree.root->left->right = new BSTFloorCeil::Node(6);
    tree.root->right->left = new BSTFloorCeil::Node(10);
    tree.root->right->right = new BSTFloorCeil::Node(14);

    // Find floor and ceiling
    BSTFloorCeil::Node *floorNode = tree.Floor(tree.root, 7);
    int floorValue = (floorNode != nullptr) ? floorNode->data : -1;
    cout << "The floor is: " << floorValue << endl;

    int ceilValue = tree.Ceil(tree.root, 7);
    cout << "The ceiling is: " << ceilValue << endl;

    return 0;
}
