#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

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
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);
        int operations = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            std::vector<int> levelValues;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            operations += calculateMinSwaps(levelValues);
        }

        return operations;
    }

private:
    int calculateMinSwaps(const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = {nums[i], i};
        }

        std::sort(sortedNums.begin(), sortedNums.end());

        std::vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || sortedNums[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = sortedNums[j].second;
                ++cycleSize;
            }

            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};

TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (nodes[i] != -1) {
            node->left = new TreeNode(nodes[i]);
            q.push(node->left);
        }
        ++i;

        if (i < nodes.size() && nodes[i] != -1) {
            node->right = new TreeNode(nodes[i]);
            q.push(node->right);
        }
        ++i;
    }

    return root;
}

// Test cases
int main() {
    Solution solution;

    // case 1
    std::vector<int> nodes1 = {1, 4, 3, 7, 6, 8, 5, -1, -1, -1, -1, 9, -1, 10};
    TreeNode* root1 = buildTree(nodes1);
    std::cout << "Example 1 Output: " << solution.minimumOperations(root1) << std::endl;

    // case 2
    std::vector<int> nodes2 = {1, 3, 2, 7, 6, 5, 4};
    TreeNode* root2 = buildTree(nodes2);
    std::cout << "Example 2 Output: " << solution.minimumOperations(root2) << std::endl;

    // case 3
    std::vector<int> nodes3 = {1, 2, 3, 4, 5, 6};
    TreeNode* root3 = buildTree(nodes3);
    std::cout << "Example 3 Output: " << solution.minimumOperations(root3) << std::endl;

    return 0;
}
