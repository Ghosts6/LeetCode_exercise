#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

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
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        helper(root, distance, result);
        return result;
    }
    
private:
    std::vector<int> helper(TreeNode* node, int distance, int &result) {
        if (!node) return {};
        
        if (!node->left && !node->right) return {1};
        
        std::vector<int> leftDistances = helper(node->left, distance, result);
        std::vector<int> rightDistances = helper(node->right, distance, result);
        
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    result++;
                }
            }
        }
        
        std::vector<int> currentDistances;
        for (int ld : leftDistances) {
            if (ld + 1 < distance) currentDistances.push_back(ld + 1);
        }
        for (int rd : rightDistances) {
            if (rd + 1 < distance) currentDistances.push_back(rd + 1);
        }
        
        return currentDistances;
    }
};
//  test case
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    int distance = 3;
    int result = solution.countPairs(root, distance);
    
    std::cout << "Number of good leaf node pairs: " << result << std::endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
