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
    void findDepthAndParent(TreeNode* node, int target, int depth, TreeNode* parent, int& foundDepth, TreeNode*& foundParent) {
        if (!node) return;

        if (node->val == target) {
            foundDepth = depth;
            foundParent = parent;
            return;
        }

        findDepthAndParent(node->left, target, depth + 1, node, foundDepth, foundParent);
        findDepthAndParent(node->right, target, depth + 1, node, foundDepth, foundParent);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = -1, depthY = -1;
        TreeNode* parentX = nullptr;
        TreeNode* parentY = nullptr;

        findDepthAndParent(root, x, 0, nullptr, depthX, parentX);
        findDepthAndParent(root, y, 0, nullptr, depthY, parentY);

        return (depthX == depthY) && (parentX != parentY);
    }
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, nullptr, new TreeNode(4));
    root->right = new TreeNode(3);
    return root;
}
//  Test cases
int main() {
    Solution sol;

    // Case 1
    TreeNode* root1 = createTree();
    int x1 = 4, y1 = 3;
    std::cout << "Test Case 1: " << (sol.isCousins(root1, x1, y1) ? "true" : "false") << std::endl; // Expected Output: false

    // Case 2
    TreeNode* root2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(5)));
    int x2 = 5, y2 = 4;
    std::cout << "Test Case 2: " << (sol.isCousins(root2, x2, y2) ? "true" : "false") << std::endl; // Expected Output: true

    // Case 3
    TreeNode* root3 = createTree();
    int x3 = 2, y3 = 3;
    std::cout << "Test Case 3: " << (sol.isCousins(root3, x3, y3) ? "true" : "false") << std::endl; // Expected Output: false

    return 0;
}
