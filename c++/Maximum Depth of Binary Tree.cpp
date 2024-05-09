#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
//  test case
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    int depth = solution.maxDepth(root);
    std::cout << "maximum depth of the binary tree are equal with: " << depth << std::endl;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
