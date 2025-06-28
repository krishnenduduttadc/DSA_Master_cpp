#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

string serialize(Node *root)
{
    if (root == nullptr)
        return "";
    queue<Node *> q;
    stringstream ss;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node == nullptr)
        {
            ss << "n ";
            continue;
        }
        ss << node->val << " ";
        q.push(node->left);
        q.push(node->right);
    }
    return ss.str();
}

Node *deserialize(string data)
{
    if (data.empty())
        return nullptr;
    stringstream ss(data);
    string str;
    ss >> str;
    if (str == "n")
        return nullptr;
    Node *root = new Node(stoi(str));
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();
        if (!(ss >> str))
            break;
        if (str != "n")
        {
            Node *leftChild = new Node(stoi(str));
            parent->left = leftChild;
            q.push(leftChild);
        }
        if (!(ss >> str))
            break;
        if (str != "n")
        {
            Node *rightChild = new Node(stoi(str));
            parent->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

void printTree(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node == nullptr)
        {
            cout << "n ";
        }
        else
        {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    Node *deserialized = deserialize(serialized);
    cout << "Deserialized tree: ";
    printTree(deserialized);

    return 0;
}
