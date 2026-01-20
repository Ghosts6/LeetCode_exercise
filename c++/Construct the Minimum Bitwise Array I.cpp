#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                ans[i] = -1;
            } else {
                // Find the lowest bit in the trailing block of 1s to flip
                for (int bit = 0; bit < 31; ++bit) {
                    if (!((nums[i] >> (bit + 1)) & 1)) {
                        ans[i] = nums[i] ^ (1 << bit);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

// Test cases
int main() {
    Solution sol;

    // Case 1
    std::vector<int> nums1 = {2, 3, 5, 7};
    std::vector<int> res1 = sol.minBitwiseArray(nums1);
    std::cout << "Result 1: ";
    for (int x : res1) std::cout << x << " ";
    std::cout << std::endl;

    // Case 2
    std::vector<int> nums2 = {11, 13, 31};
    std::vector<int> res2 = sol.minBitwiseArray(nums2);
    std::cout << "Result 2: ";
    for (int x : res2) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
