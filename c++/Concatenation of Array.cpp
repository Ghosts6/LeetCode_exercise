#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(2 * n); 
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
        }
        for (int i = 0; i < n; ++i) {
            ans[i + n] = nums[i];
        }
        return ans;
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> ans = sol.getConcatenation(nums);
    std::cout << "result ";
    for (int num : ans) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
