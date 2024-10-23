#include <iostream>
#include <queue>
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        dfs(std::vector<TreeNode*>{root});
        return root;
    }

private:
    void dfs(std::vector<TreeNode*> arr) {
        if (arr.empty()) return;

        int sum = 0;
        for (auto node : arr) {
            if (!node) continue;
            if (node->left) sum += node->left->val;
            if (node->right) sum += node->right->val;
        }

        std::vector<TreeNode*> childArr;
        for (auto node : arr) {
            int curSum = 0;
            if (node->left) curSum += node->left->val;
            if (node->right) curSum += node->right->val;

            if (node->left) {
                node->left->val = sum - curSum;
                childArr.push_back(node->left);
            }
            if (node->right) {
                node->right->val = sum - curSum;
                childArr.push_back(node->right);
            }
        }

        dfs(childArr);
    }
};

TreeNode* createTree1() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(10);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* createTree2() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        std::cout << node->val << " ";
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    
    std::cout << std::endl;
}

int main() {
    Solution sol;

    // Case 1
    TreeNode* root1 = createTree1();
    std::cout << "Original Tree 1: ";
    printTree(root1);
    root1 = sol.replaceValueInTree(root1);
    std::cout << "Modified Tree 1: ";
    printTree(root1); // Expected Output: [0,0,0,7,7,null,11]

    // Case 2
    TreeNode* root2 = createTree2();
    std::cout << "Original Tree 2: ";
    printTree(root2);
    root2 = sol.replaceValueInTree(root2);
    std::cout << "Modified Tree 2: ";
    printTree(root2); // Expected Output: [0,0,0]

    return 0;
}
