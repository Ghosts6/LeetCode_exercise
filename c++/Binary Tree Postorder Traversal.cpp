#include <iostream>
#include <vector>
#include <stack>

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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) return result;

        std::stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* curr = nodes.top();
            nodes.pop();
            result.insert(result.begin(), curr->val);

            if (curr->left != nullptr) {
                nodes.push(curr->left);
            }
            if (curr->right != nullptr) {
                nodes.push(curr->right);
            }
        }

        return result;
    }
};
// test case
int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    std::vector<int> postorder = solution.postorderTraversal(root);

    std::cout << "postorder traversal: ";
    for (int val : postorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
