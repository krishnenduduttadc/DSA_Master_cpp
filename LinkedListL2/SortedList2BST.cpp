#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* convertToBST(ListNode* head, ListNode* tail) {
    if (head == tail) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != tail && fast->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = convertToBST(head, slow);
    root->right = convertToBST(slow->next, tail);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) return nullptr;
    return convertToBST(head, nullptr);
}

void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    TreeNode* result = sortedListToBST(head);
    printTree(result);
    cout << endl;

    return 0;
}