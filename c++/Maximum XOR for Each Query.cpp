#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int totalXor = 0;
        for (int num : nums) {
            totalXor ^= num;
        }
        
        int mask = (1 << maximumBit) - 1;
        std::vector<int> answer(n);
        
        for (int i = 0; i < n; ++i) {
            answer[i] = totalXor ^ mask;
            totalXor ^= nums[n - 1 - i];
        }
        
        return answer;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {0, 1, 1, 3};
    int maximumBit1 = 2;
    auto result1 = solution.getMaximumXor(nums1, maximumBit1);
    std::cout << "Output for nums = [0,1,1,3], maximumBit = 2: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // case 2
    std::vector<int> nums2 = {2, 3, 4, 7};
    int maximumBit2 = 3;
    auto result2 = solution.getMaximumXor(nums2, maximumBit2);
    std::cout << "Output for nums = [2,3,4,7], maximumBit = 3: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // case 3
    std::vector<int> nums3 = {0, 1, 2, 2, 5, 7};
    int maximumBit3 = 3;
    auto result3 = solution.getMaximumXor(nums3, maximumBit3);
    std::cout << "Output for nums = [0,1,2,2,5,7], maximumBit = 3: ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}