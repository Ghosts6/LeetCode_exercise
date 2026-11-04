#include <iostream>
#include <vector>

class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int moves = 0;

        for (int num : nums) {
            moves += num - minVal;
        }

        return moves;
    }
};

// Test cases
int main() {
    Solution sol;
    
    // case 1
    std::vector<int> nums1 = {1, 2, 3};
    std::cout<< "Result of test case 1 : " << sol.minMoves(nums1) << std::endl; // Expected: 3

    // case 2
    std::vector<int> nums2 = {1, 1, 1};
    std::cout<< "Result of test case 2 : " << sol.minMoves(nums2) << std::endl; // Expected: 0

    return 0;
}
