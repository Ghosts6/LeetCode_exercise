#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int inc = 1, dec = 1, ans = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++inc;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                ++dec;
                inc = 1;
            }
            else {
                inc = dec = 1;
            }

            ans = std::max(ans, std::max(inc, dec));
        }

        return ans;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> nums1 = {1, 4, 3, 3, 2};
    std::cout<< "Result of test case1 : " << sol.longestMonotonicSubarray(nums1) << std::endl; // Expected: 2

    // case 2
    std::vector<int> nums2 = {3, 3, 3, 3};
    std::cout<< "Result of test case2 : " << sol.longestMonotonicSubarray(nums2) << std::endl; // Expected: 1

    // case 3
    std::vector<int> nums3 = {3, 2, 1};
    std::cout<< "Result of test case3 : " << sol.longestMonotonicSubarray(nums3) << std::endl; // Expected: 3

    return 0;
}
