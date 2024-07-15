#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (const auto& description : descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            bool isLeft = description[2] == 1;

            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }

            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }

            children.insert(childVal);
        }

   
        TreeNode* root = nullptr;
        for (const auto& pair : nodes) {
            if (children.find(pair.first) == children.end()) {
                root = pair.second;
                break;
            }
        }

        return root;
    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Test cases
int main() {
    Solution solution;
    vector<vector<int>> descriptions = {
        {1, 2, 1},
        {1, 3, 0},
        {2, 4, 1},
        {2, 5, 0}
    };

    TreeNode* root = solution.createBinaryTree(descriptions);
    printTree(root);
    return 0;
}
