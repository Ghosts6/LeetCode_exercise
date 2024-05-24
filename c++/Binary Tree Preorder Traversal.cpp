#include <iostream>
#include <vector>

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
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        preorder(root, result);
        return result;
    }
private:
    void preorder(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }
};

TreeNode* createTree() {
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node1 = new TreeNode(1, node2, node3);
    return node1;
}
//  test case
int main() {
    Solution solution;
    TreeNode* root = createTree();
    std::vector<int> result = solution.preorderTraversal(root);

    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    delete root->left->left; 
    delete root->left->right; 
    delete root->left; 
    delete root->right; 
    delete root; 
    return 0;
}
