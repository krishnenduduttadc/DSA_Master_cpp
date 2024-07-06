#include <iostream>
using namespace std;

class ElementsinRange {
public:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    static void elementsInRangeK1K2(Node* root, int k1, int k2) {
        if (root == nullptr) {
            return;
        }

        if (root->key >= k1 && root->key <= k2) {
            cout << root->key << " ";
        }

        if (root->key > k1) {
            elementsInRangeK1K2(root->left, k1, k2);
        }

        if (root->key < k2) {
            elementsInRangeK1K2(root->right, k1, k2);
        }
    }
};

int main() {
    ElementsinRange::Node* root = new ElementsinRange::Node(6);
    root->left = new ElementsinRange::Node(3);
    root->right = new ElementsinRange::Node(8);
    root->right->left = new ElementsinRange::Node(7);
    root->right->right = new ElementsinRange::Node(9);

    cout << "Elements in range [5, 8]: ";
    ElementsinRange::elementsInRangeK1K2(root, 5, 8);
    cout << endl;

    return 0;
}
