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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;  
        if (!root1 || !root2) return false; 
        if (root1->val != root2->val) return false; 

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

TreeNode* createTestTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    return root;
}

TreeNode* createTestTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(7);
    return root;
}

TreeNode* createEmptyTree() {
    return nullptr;
}
//  Test cases
int main() {
    Solution solution;
    // case 1
    TreeNode* root1 = createTestTree1();
    TreeNode* root2 = createTestTree2();
    std::cout << (solution.flipEquiv(root1, root2) ? "True" : "False") << std::endl; // Expected: True
    // case 2
    TreeNode* root3 = createEmptyTree();
    TreeNode* root4 = createEmptyTree();
    std::cout << (solution.flipEquiv(root3, root4) ? "True" : "False") << std::endl; // Expected: True
    // case 3
    TreeNode* root5 = createEmptyTree();
    TreeNode* root6 = new TreeNode(1);
    std::cout << (solution.flipEquiv(root5, root6) ? "True" : "False") << std::endl; // Expected: False

    return 0;
}
