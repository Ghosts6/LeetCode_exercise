#include <iostream>
#include <algorithm>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return std::abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(getHeight(root->left), getHeight(root->right));
    }
};
// test case
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    bool result = solution.isBalanced(root);
    std::cout << "is the binary tree height-balanced? " << (result ? "Yes" : "No") << std::endl;
    return 0;
}
