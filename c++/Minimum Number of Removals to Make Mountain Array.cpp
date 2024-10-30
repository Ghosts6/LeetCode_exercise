#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumMountainRemovals(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> lis(n, 1), lds(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = std::max(lis[i], lis[j] + 1);
                }
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = std::max(lds[i], lds[j] + 1);
                }
            }
        }

        int max_mountain_len = 0;

        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) { 
                max_mountain_len = std::max(max_mountain_len, lis[i] + lds[i] - 1);
            }
        }

        return n - max_mountain_len;
    }
};
// Test cases
int main() {
    Solution solution;
    
    // Case 1
    std::vector<int> nums1 = {1, 3, 1};
    std::cout << "Minimum removals for Test Case 1: " << solution.minimumMountainRemovals(nums1) << std::endl;
    
    // Case 2
    std::vector<int> nums2 = {2, 1, 1, 5, 6, 2, 3, 1};
    std::cout << "Minimum removals for Test Case 2: " << solution.minimumMountainRemovals(nums2) << std::endl;

    return 0;
}
