#include <iostream>
#include <climits>
#include <unordered_set>

class BST
{
private:
    struct Node
    {
        int key, lcount;
        Node *left, *right;

        Node(int item)
        {
            key = item;
            left = nullptr;
            right = nullptr;
            lcount = 0;
        }
    };

    Node *root;

    Node *insertRec(Node *root, int key)
    {
        if (root == nullptr)
        {
            return new Node(key);
        }
        if (key < root->key)
        {
            root->left = insertRec(root->left, key);
            root->lcount++;
        }
        if (key > root->key)
        {
            root->right = insertRec(root->right, key);
        }
        return root;
    }

    static void Inorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            Inorder(root->left);
            std::cout << root->key << " ";
            Inorder(root->right);
        }
    }

    static bool searchRec(Node *root, int x)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (x == root->key)
        {
            return true;
        }
        if (x < root->key)
        {
            return searchRec(root->left, x);
        }
        if (x > root->key)
        {
            return searchRec(root->right, x);
        }
        return false;
    }

    static bool searchI(Node *root, int x)
    {
        Node *curr = root;
        while (curr != nullptr)
        {
            if (x == curr->key)
            {
                return true;
            }
            if (x < curr->key)
            {
                curr = curr->left;
            }
            if (x > curr->key)
            {
                curr = curr->right;
            }
        }
        return false;
    }

    static Node *kthSmallest(Node *root, int k)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        int count = root->lcount + 1;
        if (count == k)
        {
            return root;
        }
        if (count > k)
        {
            return kthSmallest(root->left, k);
        }
        return kthSmallest(root->right, k - count);
    }

    static Node *floor(Node *root, int x)
    {
        Node *res = nullptr;
        while (root != nullptr)
        {
            if (x == root->key)
            {
                return root;
            }
            else if (x < root->key)
            {
                root = root->left;
            }
            else
            {
                res = root;
                root = root->right;
            }
        }
        return res;
    }

    static Node *ceiling(Node *root, int x)
    {
        Node *res = nullptr;
        while (root != nullptr)
        {
            if (x == root->key)
            {
                return root;
            }
            else if (x < root->key)
            {
                res = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return res;
    }

    static bool isBST(Node *root, int min, int max)
    {
        if (root == nullptr)
        {
            return true;
        }
        return (root->key > min && root->key < max && isBST(root->left, min, root->key) && isBST(root->right, root->key, max));
    }

    static bool isPairSum(Node *root, int sum, std::unordered_set<int> &s)
    {
        if (root == nullptr)
            return false;
        if (isPairSum(root->left, sum, s))
        {
            return true;
        }
        if (s.find(sum - root->key) != s.end())
        {
            return true;
        }
        else
        {
            s.insert(root->key);
        }
        return isPairSum(root->right, sum, s);
    }

public:
    BST() : root(nullptr) {}

    void insert(int key)
    {
        root = insertRec(root, key);
    }

    void inorder()
    {
        Inorder(root);
        std::cout << std::endl;
    }

    bool search(int x)
    {
        return searchRec(root, x);
    }

    bool searchIterative(int x)
    {
        return searchI(root, x);
    }

    int kthSmallest(int k)
    {
        Node *result = kthSmallest(root, k);
        return result ? result->key : -1;
    }

    int floorValue(int x)
    {
        Node *result = floor(root, x);
        return result ? result->key : -1;
    }

    int ceilingValue(int x)
    {
        Node *result = ceiling(root, x);
        return result ? result->key : -1;
    }

    bool isBST()
    {
        return isBST(root, INT_MIN, INT_MAX);
    }

    bool isPairSum(int sum)
    {
        std::unordered_set<int> s;
        return isPairSum(root, sum, s);
    }
};

int main()
{
    BST tree;

    int data[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i : data)
    {
        tree.insert(i);
    }

    std::cout << "Inorder traversal: ";
    tree.inorder();

    std::cout << "80 present? " << (tree.search(80) ? "Yes" : "No") << std::endl;
    std::cout << "90 present? " << (tree.search(90) ? "Yes" : "No") << std::endl;

    std::cout << "81 present? " << (tree.searchIterative(81) ? "Yes" : "No") << std::endl;
    std::cout << "Is BST? " << (tree.isBST() ? "Yes" : "No") << std::endl;

    std::cout << "Floor of 58? " << tree.floorValue(58) << std::endl;
    std::cout << "Ceiling of 58? " << tree.ceilingValue(58) << std::endl;

    std::cout << "4th smallest element? " << tree.kthSmallest(4) << std::endl;

    std::cout << "Pair with sum 70? " << (tree.isPairSum(70) ? "Yes" : "No") << std::endl;

    return 0;
}