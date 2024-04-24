#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;        
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];     
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return sum; 
                if (std::abs(sum - target) < std::abs(closestSum - target)) {
                    closestSum = sum; 
                }
                if (sum < target) {
                    ++left; 
                } else {
                    --right;
                }
            }
        }
        return closestSum;
    }
};
// test case
int main() {
    Solution sol;
    std::vector<int> nums = {-1, 2, 1, -4, 5};
    int target = 1;
    int result = sol.threeSumClosest(nums, target); // Expected output: 2
    std::cout<<"result :"<<result<<std::endl;
    return 0;
}
