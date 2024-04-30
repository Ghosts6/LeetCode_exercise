#include <iostream>
#include <queue>

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
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            int size = q.size();
            sum = 0; 
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return sum;
    }
};

// test case
int main() {
    Solution sol;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(9);
    root->left->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(5);
    std::cout << "result of test case: " << sol.deepestLeavesSum(root) << std::endl;
    // clean memory
    delete root->left->left->left;
    delete root->left->right->right;
    delete root->right->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
