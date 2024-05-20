#include <iostream>
#include <vector>

class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int subsetCount = 1 << n; 
        
        for (int i = 0; i < subsetCount; ++i) {
            int currentXOR = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentXOR ^= nums[j];
                }
            }
            totalSum += currentXOR;
        }
        
        return totalSum;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<int> nums = {2, 4, 6, 8};
    std::cout << "sum of all XOR totals for nums: " << solution.subsetXORSum(nums) << std::endl;
    return 0;
}
