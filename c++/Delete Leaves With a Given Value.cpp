#include <iostream>

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (!root->left && !root->right && root->val == target)
            return nullptr;
        return root;
    }
};


void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

// test case
int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(2);

    int target = 2;

    root = solution.removeLeafNodes(root, target);

    std::cout << "result of test case: ";
    printInOrder(root);
    std::cout << std::endl;

    // clean memory
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
    
    return 0;
}
