#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<bool> isArraySpecial(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        std::vector<bool> parityDiff(n - 1, false);
        for (int i = 0; i < n - 1; ++i) {
            parityDiff[i] = (nums[i] % 2 != nums[i + 1] % 2);
        }
        
        std::vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + parityDiff[i - 1];
        }

        std::vector<bool> result;
        for (const auto& query : queries) {
            int from = query[0], to = query[1];
            if (to == from) {
                result.push_back(true);
            } else {
                int count = prefixSum[to] - prefixSum[from];
                result.push_back(count == to - from);
            }
        }

        return result;
    }
};
// Test cases
int main() {
    Solution solution;

    // case 1
    std::vector<int> nums1 = {3, 4, 1, 2, 6};
    std::vector<std::vector<int>> queries1 = {{0, 4}};
    auto result1 = solution.isArraySpecial(nums1, queries1);
    for (bool res : result1) {
        std::cout << (res ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    // case 2
    std::vector<int> nums2 = {4, 3, 1, 6};
    std::vector<std::vector<int>> queries2 = {{0, 2}, {2, 3}};
    auto result2 = solution.isArraySpecial(nums2, queries2);
    for (bool res : result2) {
        std::cout << (res ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    return 0;
}
