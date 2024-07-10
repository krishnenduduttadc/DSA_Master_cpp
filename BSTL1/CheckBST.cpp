#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

class CheckBST
{
public:
    struct Node
    {
        int key;
        Node *left;
        Node *right;

        Node(int item)
        {
            key = item;
            left = nullptr;
            right = nullptr;
        }
    };

    static int max(Node *root)
    {
        if (root == nullptr)
        {
            return INT_MIN;
        }
        return std::max(root->key, std::max(max(root->left), max(root->right)));
    }

    static int min(Node *root)
    {
        if (root == nullptr)
        {
            return INT_MAX;
        }
        return std::min(root->key, std::min(min(root->left), min(root->right)));
    }

    static bool isBST(Node *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        int lmax = max(root->left);
        int rmin = min(root->right);
        if (root->key < lmax || root->key > rmin)
        {
            return false;
        }
        bool isLeftBST = isBST(root->left);
        bool isRightBST = isBST(root->right);
        return isLeftBST && isRightBST;
    }
};

int main()
{
    CheckBST::Node *root = new CheckBST::Node(6);
    root->left = new CheckBST::Node(3);
    root->right = new CheckBST::Node(8);
    root->right->left = new CheckBST::Node(7);
    root->right->right = new CheckBST::Node(9);

    cout << "Is BST? " << (CheckBST::isBST(root) ? "Yes" : "No") << endl;

    return 0;
}
