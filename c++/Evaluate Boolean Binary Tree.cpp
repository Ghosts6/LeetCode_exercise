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
    bool evaluateTree(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->val == 1;
        }

        bool left_val = evaluateTree(root->left);
        bool right_val = evaluateTree(root->right);

        if (root->val == 2) {
            return left_val || right_val;
        } else { 
            return left_val && right_val;
        }
    }
};
// test cases
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(0);

    Solution solution;
    std::cout << "result: " << std::boolalpha << solution.evaluateTree(root) << std::endl;

    // clean memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
