#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxLength(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                g = std::gcd(g, nums[j]);
                l = std::lcm(l, (long long)nums[j]);
                product *= nums[j];

                if (product == l * g) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

// Test case
int main() {
    Solution sol;

    // case 1
    std::vector<int> nums1 = {1, 2, 1, 2, 1, 1, 1};
    std::cout << "Result of test case 1 : " << sol.maxLength(nums1) << std::endl; // Expected: 5

    // case 2
    std::vector<int> nums2 = {2, 3, 4, 5, 6};
    std::cout << "Result of test case 2 : " << sol.maxLength(nums2) << std::endl; // Expected: 3

    // case 3
    std::vector<int> nums3 = {1, 2, 3, 1, 4, 5, 1};
    std::cout << "Result of test case 3 : " << sol.maxLength(nums3) << std::endl; // Expected: 5

    return 0;
}
