#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        std::unordered_map<std::string, int> memo;
        return dfs(nums, 0, target, memo);
    }

private:
    int dfs(const std::vector<int>& nums, int index, int target, std::unordered_map<std::string, int>& memo) {
        if (index == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        std::string key = std::to_string(index) + "," + std::to_string(target);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int add = dfs(nums, index + 1, target - nums[index], memo);
        int subtract = dfs(nums, index + 1, target + nums[index], memo);

        memo[key] = add + subtract;
        return memo[key];
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    std::cout << "Test Case 1 Output: " << solution.findTargetSumWays(nums1, target1) << std::endl;
    // case 2
    std::vector<int> nums2 = {1};
    int target2 = 1;
    std::cout << "Test Case 2 Output: " << solution.findTargetSumWays(nums2, target2) << std::endl;

    return 0;
}