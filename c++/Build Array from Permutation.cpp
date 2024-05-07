#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

// test case
int main() {
    Solution sol;
    std::vector<int> nums = {0, 2, 1, 5, 3, 4};
    std::vector<int> ans = sol.buildArray(nums);
    int n = ans.size();
    std::cout << "result: ";
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}