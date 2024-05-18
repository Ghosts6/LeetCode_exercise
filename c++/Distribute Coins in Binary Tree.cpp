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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        postorder(root, moves);
        return moves;
    }
    
private:
    int postorder(TreeNode* node, int& moves) {
        if (!node) return 0;
        int leftBalance = postorder(node->left, moves);
        int rightBalance = postorder(node->right, moves);
        int balance = node->val + leftBalance + rightBalance - 1;
        moves += abs(balance);
        return balance;
    }
};


void testDistributeCoins(const std::vector<int>& treeValues) {
    TreeNode* root = new TreeNode(treeValues[0]);
    root->left = new TreeNode(treeValues[1]);
    root->right = new TreeNode(treeValues[2]);

    Solution solution;
    int result = solution.distributeCoins(root);
    std::cout << "minimum moves: " << result << std::endl;

    delete root->left;
    delete root->right;
    delete root;
}
//  tets cases
int main() {
    testDistributeCoins({3, 0, 0});
    testDistributeCoins({0, 3, 0});
    
    return 0;
}
