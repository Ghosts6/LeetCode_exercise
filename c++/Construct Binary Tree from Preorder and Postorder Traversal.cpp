#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int preIndex = 0, postIndex = 0;

    TreeNode* build(std::vector<int>& preorder, std::vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (root->val != postorder[postIndex]) {
            root->left = build(preorder, postorder);
        }
        if (root->val != postorder[postIndex]) {
            root->right = build(preorder, postorder);
        }
        
        postIndex++;  
        return root;
    }

public:
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        preIndex = postIndex = 0;  
        return build(preorder, postorder);
    }
};

// Helper function
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

// Test case
int main() {
    Solution solution;

    // Case 1
    std::vector<int> preorder1 = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> postorder1 = {4, 5, 2, 6, 7, 3, 1};

    TreeNode* root1 = solution.constructFromPrePost(preorder1, postorder1);
    inorder(root1);
    std::cout << std::endl; // Expected Output: 4 2 5 1 6 3 7 (Inorder traversal)

    // Case 2
    std::vector<int> preorder2 = {1};
    std::vector<int> postorder2 = {1};

    TreeNode* root2 = solution.constructFromPrePost(preorder2, postorder2);
    inorder(root2);
    std::cout << std::endl; // Expected Output: 1 (Inorder traversal)

    return 0;
}