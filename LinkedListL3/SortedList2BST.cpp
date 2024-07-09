#include <iostream>

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class ConvertSortedListToBST {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        return convertToBST(head, nullptr);
    }

private:
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

public:
    static void printTree(TreeNode* root) {
        if (root != nullptr) {
            printTree(root->left);
            std::cout << root->val << " ";
            printTree(root->right);
        }
    }
};

int main() {
    ConvertSortedListToBST solution;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    TreeNode* result = solution.sortedListToBST(head);
    ConvertSortedListToBST::printTree(result);

    return 0;
}
