#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long longestSquareStreak(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::unordered_set<long long> numSet(nums.begin(), nums.end());
        long long maxStreakLength = -1;

        for (int num : nums) {
            if (numSet.find(num) == numSet.end()) {
                continue;
            }
            long long current = num;
            long long streakLength = 0;

            while (numSet.find(current) != numSet.end()) {
                streakLength++;
                numSet.erase(current);

                if (current > LLONG_MAX / current) {
                    break;
                }
                current *= current;
            }
            if (streakLength >= 2) {
                maxStreakLength = std::max(maxStreakLength, streakLength);
            }
        }

        return maxStreakLength;
    }
};
//  Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {4, 3, 6, 16, 8, 2};
    std::cout << "Test Case 1: " << solution.longestSquareStreak(nums1) << std::endl; // Expected Output: 3

    // case 2
    std::vector<int> nums2 = {2, 3, 5, 6, 7};
    std::cout << "Test Case 2: " << solution.longestSquareStreak(nums2) << std::endl; // Expected Output: -1

    return 0;
}
