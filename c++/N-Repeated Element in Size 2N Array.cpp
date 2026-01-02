#include <iostream>
#include <vector>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        int size = nums.size();
        
        for (int distance = 1; distance <= 3; ++distance) {
            for (int i = 0; i < size - distance; ++i) {
                if (nums[i] == nums[i + distance]) {
                    return nums[i];
                }
            }
        }
        
        return -1;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> nums1 = {1, 2, 3 , 3};
    std::cout << "Result of test case 1 : " << sol.repeatedNTimes(nums1) << std::endl; // Expected: 3

    // case 2
    std::vector<int> nums2 = {2, 1, 2, 5, 3, 2};
    std::cout << "Result of test case 2 : " << sol.repeatedNTimes(nums2) << std::endl; // Expected: 2

    // case 3
    std::vector<int> nums3 = {5, 1, 5, 2, 5, 3, 5, 4};
    std::cout << "Result of test case 3 : " << sol.repeatedNTimes(nums3) << std::endl; // Expected: 5     
    
    return 0;
}
