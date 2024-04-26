#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);
        backtrack(nums, result, current, used);
        return result;
    }
private:
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& current, std::vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                current.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, result, current, used);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> permutations = sol.permute(nums);
    for (const auto& perm : permutations) {
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}