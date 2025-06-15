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

void inOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void levelOrderTraversal(Node *root)
{
    if (root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        
        for (int i = 0; i < s; i++)
        {
            Node* curr = q.front();
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

int main()
{
    // ✅ Hardcoded input
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = insertLevelOrder(arr, nullptr, 0, n);
    
    cout << "In-order Traversal of the Binary Tree: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Level-order Traversal of the Binary Tree:\n";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
