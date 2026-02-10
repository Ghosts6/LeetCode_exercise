#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestBalanced(const std::vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinctEvens;
            std::unordered_set<int> distinctOdds;

            for (int j = i; j < n; ++j) {
                if (nums[j] % 2 == 0) {
                    distinctEvens.insert(nums[j]);
                } else {
                    distinctOdds.insert(nums[j]);
                }

                if (distinctEvens.size() == distinctOdds.size()) {
                    maxLength = std::max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }
};
// Test cases
int main() {
    Solution sol;

    // Test Case 1
    std::vector<int> nums1 = {2, 5, 4, 3};
    std::cout << "Result of Test Case 1: " << sol.longestBalanced(nums1) << " (Expected: 4)" << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {3, 2, 2, 5, 4};
    std::cout << "Result of Test Case 2: " << sol.longestBalanced(nums2) << " (Expected: 5)" << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {1, 2, 3, 2};
    std::cout << "Result of Test Case 3: " << sol.longestBalanced(nums3) << " (Expected: 3)" << std::endl;

    return 0;
}
