#include <iostream>
#include <vector>
#include <queue>

// TreeNode structure definition
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

// Function to perform zigzag level order traversal
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> wrapList;
    if (root == nullptr) return wrapList;

    std::queue<TreeNode*> queue;
    queue.push(root);
    bool flag = true; // Flag to control direction of traversal

    while (!queue.empty()) {
        int levelNum = queue.size();
        std::vector<int> subList(levelNum);

        for (int i = 0; i < levelNum; i++) {
            TreeNode* node = queue.front();
            queue.pop();

            int index = (flag) ? i : (levelNum - 1 - i);
            subList[index] = node->key;

            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);
        }
        
        wrapList.push_back(subList);
        flag = !flag; // Flip the flag for the next level
    }
    
    return wrapList;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> ans = zigzagLevelOrder(root);

    std::cout << "Zig Zag Traversal of Binary Tree: " << std::endl;
    for (size_t i = 0; i < ans.size(); i++) {
        for (size_t j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocating memory
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
