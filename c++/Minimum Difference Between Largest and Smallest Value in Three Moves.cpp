#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        
        std::sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        
        for (int i = 0; i <= 3; ++i) {
            min_diff = std::min(min_diff, nums[n - 4 + i] - nums[i]);
        }
        
        return min_diff;
    }
};
//  test cases
int main() {
    Solution solution;
    std::vector<int> nums1 = {5, 3, 2, 4};
    std::vector<int> nums2 = {1, 5, 0, 10, 14};

    
    std::cout << "Test Case 1: " << solution.minDifference(nums1) << std::endl; 
    std::cout << "Test Case 2: " << solution.minDifference(nums2) << std::endl; 
    
    return 0;
}
