#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};

void treeToList(Node* root, vector<int>& list) {
    if (root == nullptr) return;
    treeToList(root->left, list);
    list.push_back(root->key);
    treeToList(root->right, list);
}

bool isPairPresent(Node* root, int target) {
    vector<int> nodeList;
    treeToList(root, nodeList);

    int start = 0;
    int end = nodeList.size() - 1;

    while (start < end) {
        int sum = nodeList[start] + nodeList[end];
        if (sum == target) {
            cout << "Pair Found: " << nodeList[start] << " + " << nodeList[end] << " = " << target << endl;
            return true;
        } else if (sum < target) {
            start++;
        } else {
            end--;
        }
    }

    cout << "No such values are found!" << endl;
    return false;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);

    int sum = 33;

    isPairPresent(root, sum);

    return 0;
}
