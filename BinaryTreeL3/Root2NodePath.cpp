#include <iostream>
#include <vector>
using namespace std;


struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

bool getPath(Node *root, vector<int> &arr, int x)
{
    if (root == nullptr)
        return false;

    arr.push_back(root->key);

    if (root->key == x)
        return true;

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;

    arr.pop_back();
    return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right = new Node(3);

    vector<int> arr;

    bool res = getPath(root, arr, 7);

    if (res)
    {
        cout << "The path is: ";
        for (int it : arr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Node not found in the tree." << endl;
    }

    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
