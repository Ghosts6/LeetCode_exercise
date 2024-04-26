#include <iostream>
#include <vector>
#include <cmath>

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* buildBST(std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        return root;
    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}
// test case
int main() {
    Solution sol;
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sol.sortedArrayToBST(nums);
    printTree(root);
    return 0;
}