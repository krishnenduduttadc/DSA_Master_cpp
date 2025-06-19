#include <iostream>
#include <vector>
using namespace std;


struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

bool getPath(TreeNode *root, vector<int> &arr, int x)
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);

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
