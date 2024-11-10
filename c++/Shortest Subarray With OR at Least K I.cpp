#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            int currentOR = 0;
            for (int j = i; j < n; ++j) {
                currentOR |= nums[j];
                if (currentOR >= k) {
                    minLength = std::min(minLength, j - i + 1);
                    break;
                }
            }
        }
        
        return minLength == INT_MAX ? -1 : minLength;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {1, 2, 3};
    int k1 = 2;
    std::cout << "Test case 1 - Expected: 1, Output: " << solution.minimumSubarrayLength(nums1, k1) << std::endl;
    // case 2
    std::vector<int> nums2 = {2, 1, 8};
    int k2 = 10;
    std::cout << "Test case 2 - Expected: 3, Output: " << solution.minimumSubarrayLength(nums2, k2) << std::endl;

    // case 3
    std::vector<int> nums3 = {1, 2};
    int k3 = 0;
    std::cout << "Test case 3 - Expected: 1, Output: " << solution.minimumSubarrayLength(nums3, k3) << std::endl;

    return 0;
}
