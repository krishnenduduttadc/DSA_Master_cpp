#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();

        for (int i = 0; i < s; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}

Node *insertLevelOrder(int arr[], Node *root, int i, int n)
{
    if (i >= n)
    {
        return nullptr;
    }
    Node *tmp = new Node(arr[i]);
    root = tmp;
    root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    return root;
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        return max(l, r) + 1;
    }
}

int size(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int l = size(root->left);
        int r = size(root->right);
        return l + r + 1;
    }
}

int maxValue(Node *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }
    else
    {
        int l = maxValue(root->left);
        int r = maxValue(root->right);
        return max(root->data, max(l, r));
    }
}

int main()
{
    // ✅ Hardcoded input
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = insertLevelOrder(arr, nullptr, 0, n);

    cout << "Level-order Traversal of the Binary Tree:\n";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Height: " << height(root) << endl;
    cout << "Size: " << size(root) << endl;
    cout << "Max Value: " << maxValue(root) << endl;

    return 0;
}
