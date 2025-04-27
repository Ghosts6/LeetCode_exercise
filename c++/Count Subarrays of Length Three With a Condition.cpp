#include<iostream>
#include<vector>

class Solution {
    public:
    int countSubarrays(std::vector<int>& nums){
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == 2 * (nums[i - 1] + nums[i + 1])) {
                ++count;
            }
        }
        return count;
    }
};

// Test cases
int main() {
    Solution obj;

    // case 1
    std::vector<int> nums1 = {1, 2, 1, 4, 1};
    std::cout << "result of test case 1 :" << obj.countSubarrays(nums1) << std::endl; // Expected Output: 1

    // case 2
    std::vector<int> nums2 = {1, 1, 1};
    std::cout << "result of test case 2 :" << obj.countSubarrays(nums2) << std::endl; // Expected Output: 0

    return 0;
}
