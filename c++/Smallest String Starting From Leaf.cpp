/**
 * Daily challenge
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        
        string current_path = "";
        string smallest = string(1, char('z' + 1)); 
        
        dfs(root, current_path, smallest);
        
        return smallest;
    }

private:
    void dfs(TreeNode* node, string current_path, string& smallest) {
        if (!node) return;
        
        current_path = char(node->val + 'a') + current_path;
        
        if (!node->left && !node->right) {
            smallest = min(smallest, current_path);
        }
        
        dfs(node->left, current_path, smallest);
        dfs(node->right, current_path, smallest); 
    }
};
