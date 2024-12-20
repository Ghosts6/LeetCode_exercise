#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        std::queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false;

        while (!q.empty()) {
            int size = q.size();
            std::vector<TreeNode*> levelNodes;

            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();

                if (isOddLevel) {
                    levelNodes.push_back(current);
                }

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            if (isOddLevel) {
                int n = levelNodes.size();
                for (int i = 0; i < n / 2; ++i) {
                    std::swap(levelNodes[i]->val, levelNodes[n - i - 1]->val);
                }
            }

            isOddLevel = !isOddLevel;
        }

        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->val << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    std::cout << std::endl;
}

// Test cases
int main() {
    // case 1
    TreeNode* root1 = new TreeNode(2, new TreeNode(3), new TreeNode(5));
    Solution solution;
    TreeNode* result1 = solution.reverseOddLevels(root1);
    std::cout << "Example 1 Output: ";
    printTree(result1);

    // case 2
    TreeNode* root2 = new TreeNode(7, new TreeNode(13), new TreeNode(11));
    TreeNode* result2 = solution.reverseOddLevels(root2);
    std::cout << "Example 2 Output: ";
    printTree(result2);

    // case 3
    TreeNode* root3 = new TreeNode(0, 
        new TreeNode(1, new TreeNode(0, new TreeNode(1), new TreeNode(1)), new TreeNode(0, new TreeNode(1), new TreeNode(1))), 
        new TreeNode(2, new TreeNode(0, new TreeNode(2), new TreeNode(2)), new TreeNode(0, new TreeNode(2), new TreeNode(2)))
    );
    TreeNode* result3 = solution.reverseOddLevels(root3);
    std::cout << "Example 3 Output: ";
    printTree(result3);

    return 0;
}
