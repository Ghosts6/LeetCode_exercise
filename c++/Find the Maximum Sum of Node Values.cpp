#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        std::vector<std::vector<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        std::vector<std::unordered_map<int, long long>> dp(n);
        return dfs(0, -1, nums, k, tree, dp);
    }
private:
    long long dfs(int node, int parent, std::vector<int>& nums, int k, std::vector<std::vector<int>>& tree, std::vector<std::unordered_map<int, long long>>& dp) {
        if (dp[node].count(nums[node])) return dp[node][nums[node]];
        long long sumWithoutXor = nums[node];
        long long sumWithXor = nums[node] ^ k;
        long long totalSumWithoutXor = sumWithoutXor;
        long long totalSumWithXor = sumWithXor;

        for (int neighbor : tree[node]) {
            if (neighbor == parent) continue;
            nums[neighbor] ^= k;
            long long childSumWithXor = dfs(neighbor, node, nums, k, tree, dp);
            nums[neighbor] ^= k; 
            long long childSumWithoutXor = dfs(neighbor, node, nums, k, tree, dp);
            totalSumWithoutXor += childSumWithoutXor;
            totalSumWithXor += childSumWithXor;
        }

        long long maxSum = std::max(totalSumWithoutXor, totalSumWithXor);
        dp[node][nums[node]] = maxSum;
        return maxSum;
    }
};
// test case
int main() {
    Solution solution;
    
    std::vector<int> nums1 = {1, 2, 1};
    int k1 = 3;
    std::vector<std::vector<int>> edges1 = {{0, 1}, {0, 2}};
    std::cout << ".ax sum for test case 1: " << solution.maximumValueSum(nums1, k1, edges1) << std::endl;

    std::vector<int> nums2 = {2, 3, 4};
    int k2 = 2;
    std::vector<std::vector<int>> edges2 = {{0, 1}, {1, 2}};
    std::cout << "max sum for test case 2: " << solution.maximumValueSum(nums2, k2, edges2) << std::endl;

    return 0;
}

