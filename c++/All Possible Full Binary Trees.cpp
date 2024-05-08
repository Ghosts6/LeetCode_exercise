#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        
        std::vector<TreeNode*> result;
        for (int i = 1; i < n; i += 2) {
            std::vector<TreeNode*> leftSubtrees = allPossibleFBT(i);
            std::vector<TreeNode*> rightSubtrees = allPossibleFBT(n - i - 1);
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

void printTree(TreeNode* root) {
    if (root) {
        std::cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    } else {
        std::cout << "null ";
    }
}
//  test case
int main() {
    Solution sol;
    int n = 5;
    std::vector<TreeNode*> trees = sol.allPossibleFBT(n);
    std::cout << "result : " << n << " nodes:\n";
    for (TreeNode* root : trees) {
        std::cout << "tree: ";
        printTree(root);
        std::cout << "\n";
    }
    return 0;
}
