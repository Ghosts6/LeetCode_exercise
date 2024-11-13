#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            long long leftBound = static_cast<long long>(lower) - nums[i];
            long long rightBound = static_cast<long long>(upper) - nums[i];

            int leftIndex = std::lower_bound(nums.begin() + i + 1, nums.end(), leftBound) - nums.begin();
            int rightIndex = std::upper_bound(nums.begin() + i + 1, nums.end(), rightBound) - nums.begin() - 1;

            if (leftIndex <= rightIndex) {
                count += (rightIndex - leftIndex + 1);
            }
        }

        return count;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {0, 1, 7, 4, 4, 5};
    int lower1 = 3, upper1 = 6;
    std::cout << "Test Case 1 Output: " << solution.countFairPairs(nums1, lower1, upper1) << std::endl; // Expected: 6
    // case 2
    std::vector<int> nums2 = {1, 7, 9, 2, 5};
    int lower2 = 11, upper2 = 11;
    std::cout << "Test Case 2 Output: " << solution.countFairPairs(nums2, lower2, upper2) << std::endl; // Expected: 1

    return 0;
}
