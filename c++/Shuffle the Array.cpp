#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> shuffled;
        for (int i = 0; i < n; ++i) {
            shuffled.push_back(nums[i]);
            shuffled.push_back(nums[i + n]);
        }
        return shuffled;
    }
};

// test case
int main() {
    Solution sol;
    std::vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    std::vector<int> result = sol.shuffle(nums, n);
    std::cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    return 0;
}
