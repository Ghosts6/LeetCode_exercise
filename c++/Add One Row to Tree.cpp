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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;       
        while (!q.empty() && currentDepth < depth - 1) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++currentDepth;
        }
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            leftNode->left = node->left;
            rightNode->right = node->right;
            node->left = leftNode;
            node->right = rightNode;
        }
        
        return root;
    }
};

// test case
int main() {
    // test node structure
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    int val = 1;
    int depth = 2;
    TreeNode* newRoot = sol.addOneRow(root, val, depth);

    std::queue<TreeNode*> q;
    q.push(newRoot);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        std::cout << std::endl;
    }

    return 0;
}
