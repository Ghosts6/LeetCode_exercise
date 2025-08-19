#include <iostream>
#include <vector>

class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        long long count = 0, result = 0;
        for (int n : nums) {
            if (n == 0) {
                count++;
                result += count;
            } else {
                count = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
    std::cout << "Result of test case 1 : " << sol.zeroFilledSubarray(nums) << std::endl;

    std::vector<int> nums2 = {0, 0, 0, 2, 0, 0};
    std::cout << "Result of test case 2 : " << sol.zeroFilledSubarray(nums2) << std::endl;

    std::vector<int> nums3 = {2, 10, 2019};
    std::cout << "Result of test case 3 : " << sol.zeroFilledSubarray(nums3) << std::endl;

    return 0;
}

