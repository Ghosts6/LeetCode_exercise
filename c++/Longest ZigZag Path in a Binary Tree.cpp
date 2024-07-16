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
    int max_length;

    Solution() : max_length(0) {}

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;

        max_length = std::max(max_length, length);

        if (isLeft) {
            dfs(node->left, false, length + 1);
            dfs(node->right, true, 1);        
        } else {
            dfs(node->right, true, length + 1); 
            dfs(node->left, false, 1);          
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);  
        dfs(root, false, 0); 
        return max_length;
    }
};
//  test case defs
void test_longestZigZag() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.longestZigZag(root);

    std::cout << "Test case result: " << result << std::endl;

    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left;
    delete root;
}

int main() {
    test_longestZigZag();
    return 0;
}
