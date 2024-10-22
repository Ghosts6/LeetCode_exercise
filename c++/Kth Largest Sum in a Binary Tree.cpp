#include <iostream>
#include <queue>
#include <vector>
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<long long> levelSums;

        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                levelSum += currentNode->val;

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }
            levelSums.push_back(levelSum);
        }

        std::sort(levelSums.begin(), levelSums.end(), std::greater<long long>());

        if (k > levelSums.size()) return -1;

        return levelSums[k - 1];
    }
};

TreeNode* createTestTree1() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(8);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);
    return root;
}

TreeNode* createTestTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    return root;
}

int main() {
    Solution solution;

    // case 1
    TreeNode* root1 = createTestTree1();
    int k1 = 2;
    std::cout << "Test Case 1 Output: " << solution.kthLargestLevelSum(root1, k1) << std::endl; // Output: 13

    // case 2
    TreeNode* root2 = createTestTree2();
    int k2 = 1;
    std::cout << "Test Case 2 Output: " << solution.kthLargestLevelSum(root2, k2) << std::endl; // Output: 3

    return 0;
}
