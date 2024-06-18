#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0, right = 0;
        int max_length = 0;
        int zeros_count = 0;
        
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeros_count++;
            }

            while (zeros_count > k) {
                if (nums[left] == 0) {
                    zeros_count--;
                }
                left++;
            }

            max_length = std::max(max_length, right - left + 1);
            right++;
        }
        
        return max_length;
    }
};
// test case
int main() {
    Solution solution;
    
    std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    int result = solution.longestOnes(nums, k);
    std::cout << "maximum number of consecutive 1's after flipping at most " << k << " zeros: " << result << std::endl; 
    
    return 0;
}
