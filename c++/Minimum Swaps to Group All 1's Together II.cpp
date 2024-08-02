#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        for (int num : nums) {
            if (num == 1) {
                totalOnes++;
            }
        }

        int maxOnesInWindow = 0;
        int currentOnesInWindow = 0;

        for (int i = 0; i < totalOnes; ++i) {
            if (nums[i] == 1) {
                currentOnesInWindow++;
            }
        }
        maxOnesInWindow = currentOnesInWindow;

        for (int i = totalOnes; i < n + totalOnes; ++i) {
            if (nums[i % n] == 1) {
                currentOnesInWindow++;
            }
            if (nums[(i - totalOnes) % n] == 1) {
                currentOnesInWindow--;
            }
            maxOnesInWindow = std::max(maxOnesInWindow, currentOnesInWindow);
        }

        return totalOnes - maxOnesInWindow;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    int result = solution.minSwaps(nums);
    std::cout << "minimum number of swaps required: " << result << std::endl;
    return 0;
}
