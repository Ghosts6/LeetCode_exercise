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
    void bstToGst(TreeNode* root, int& sum) {
        if (!root) return;
        bstToGst(root->right, sum);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        bstToGst(root, sum);
        return root;
    }
};

void printInOrder(TreeNode* node) {
    if (!node) return;
    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}
// test case
int main() {
    Solution solution;

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2, nullptr, new TreeNode(3));
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7, nullptr, new TreeNode(8));
    
    std::cout << "Original BST (In-order): ";
    printInOrder(root);
    std::cout << std::endl;
    
    solution.bstToGst(root);
    
    std::cout << "Greater Tree (In-order): ";
    printInOrder(root);
    std::cout << std::endl;

    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
