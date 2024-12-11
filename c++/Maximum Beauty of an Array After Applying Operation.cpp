#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumBeauty(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int maxBeauty = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > 2 * k) {
                ++left; 
            }
            maxBeauty = std::max(maxBeauty, right - left + 1);
        }

        return maxBeauty;
    }
};
// Test case
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {4, 6, 1, 2};
    int k1 = 2;
    std::cout << "Maximum Beauty (Test Case 1): " << solution.maximumBeauty(nums1, k1) << std::endl; // Expected Output: 3
    // case 2
    std::vector<int> nums2 = {1, 1, 1, 1};
    int k2 = 10;
    std::cout << "Maximum Beauty (Test Case 2): " << solution.maximumBeauty(nums2, k2) << std::endl; // Expected Output: 4

    return 0;
}
