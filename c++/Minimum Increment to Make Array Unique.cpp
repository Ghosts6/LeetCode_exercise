#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        
        int moves = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                moves += increment;
            }
        }
        
        return moves;
    }
};
//  test cases
int main() {
    Solution solution;
    
    // case 1
    std::vector<int> nums1 = {3, 2, 1, 2, 1, 7};
    int result1 = solution.minIncrementForUnique(nums1);
    std::cout << "Minimum moves for test case 1: " << result1 << std::endl; 
    
    // case 2
    std::vector<int> nums2 = {1, 2, 2};
    int result2 = solution.minIncrementForUnique(nums2);
    std::cout << "Minimum moves for test case 2: " << result2 << std::endl;  

    return 0;
}
