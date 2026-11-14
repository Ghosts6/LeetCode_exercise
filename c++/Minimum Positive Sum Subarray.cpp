#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long sum = 0;

            for (int j = i; j < n && j - i + 1 <= r; j++) {
                sum += nums[j];

                int len = j - i + 1;

                if (len >= l && sum > 0)
                    ans = std::min(ans, sum);
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> nums1 = {3, -2, 1, 4};
    int l1 = 2;
    int r1 = 3;
    std::cout<< "Result of test case 1 : " << sol.minimumSumSubarray(nums1, l1, r1) << std::endl; // Expected: 1
    
    // case 2
    std::vector<int> nums2 = {-2, 2, -3, 1};
    int l2 = 2;
    int r2 = 3;
    std::cout<< "Result of test case 2 : " << sol.minimumSumSubarray(nums2, l2, r2) << std::endl; // Expected: -1

    // case 3
    std::vector<int> nums3 = {1, 2, 3, 4};
    int l3 = 2;
    int r3 = 4;
    std::cout<< "Result of test case 3 : " << sol.minimumSumSubarray(nums3, l3, r3) << std::endl; // Expected: 3

    return 0;
}
