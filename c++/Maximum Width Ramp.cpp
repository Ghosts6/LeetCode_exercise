#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        std::stack<int> decreasingIndices;
        int maxWidth = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (decreasingIndices.empty() || nums[decreasingIndices.top()] > nums[i]) {
                decreasingIndices.push(i);
            }
        }

        for (int j = nums.size() - 1; j >= 0; --j) {
            while (!decreasingIndices.empty() && nums[decreasingIndices.top()] <= nums[j]) {
                maxWidth = std::max(maxWidth, j - decreasingIndices.top());
                decreasingIndices.pop();
            }
        }
        
        return maxWidth;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // case 1
    std::vector<int> nums1 = {6, 0, 8, 2, 1, 5};
    std::cout << "Input: [6, 0, 8, 2, 1, 5]\n";
    std::cout << "Output: " << solution.maxWidthRamp(nums1) << "\n"; // Expected output: 4

    // case 2
    std::vector<int> nums2 = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    std::cout << "Input: [9, 8, 1, 0, 1, 9, 4, 0, 4, 1]\n";
    std::cout << "Output: " << solution.maxWidthRamp(nums2) << "\n"; // Expected output: 7

    // Additional  Case : No ramp
    std::vector<int> nums3 = {5, 4, 3, 2, 1};
    std::cout << "Input: [5, 4, 3, 2, 1]\n";
    std::cout << "Output: " << solution.maxWidthRamp(nums3) << "\n"; // Expected output: 0

    return 0;
}
