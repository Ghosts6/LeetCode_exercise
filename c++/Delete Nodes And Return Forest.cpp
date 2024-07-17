#include <iostream>
#include <vector>
#include <unordered_set>
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
    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
        std::unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        std::vector<TreeNode*> forest;
        root = dfs(root, toDeleteSet, forest);
        if (root) {
            forest.push_back(root);
        }
        return forest;
    }

private:
    TreeNode* dfs(TreeNode* node, std::unordered_set<int>& toDeleteSet, std::vector<TreeNode*>& forest) {
        if (!node) return nullptr;

        node->left = dfs(node->left, toDeleteSet, forest);
        node->right = dfs(node->right, toDeleteSet, forest);

        if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
            if (node->left) {
                forest.push_back(node->left);
            }
            if (node->right) {
                forest.push_back(node->right);
            }
            delete node;
            return nullptr;
        }
        return node;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

void printForest(std::vector<TreeNode*> &forest) {
    for (TreeNode* tree : forest) {
        printTree(tree);
        std::cout << "\n";
    }
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// test case
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::vector<int> to_delete = {3, 5};

    Solution sol;
    std::vector<TreeNode*> forest = sol.delNodes(root, to_delete);

    std::cout << "Result of test case:\n";
    printForest(forest);

    for (TreeNode* tree : forest) {
        deleteTree(tree);
    }

    return 0;
}
