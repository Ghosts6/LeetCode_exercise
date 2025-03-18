#include<iostream>
#include<vector>

class Solution {
    public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int maxLength = 0, left = 0, bitMask = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while ((bitMask & nums[right]) != 0) {
                bitMask ^= nums[left++];
            }
            bitMask |= nums[right];
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
// main def
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {1, 3, 8, 48, 10};
    std::cout << "result for case 1 is:" << solution.longestNiceSubarray(nums1) << std::endl; // Expected output: 3

    // case 2
    std::vector<int> nums2 = {3, 1, 5, 11, 13};
    std::cout << "result for case 2 is:" << solution.longestNiceSubarray(nums2) << std::endl; // Expected output: 1

    return 0;
}