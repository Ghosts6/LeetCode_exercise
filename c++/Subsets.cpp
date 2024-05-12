#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    } 
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& subset, std::vector<std::vector<int>>& result) {
        result.push_back(subset);
        
        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
};
// test case
int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = solution.subsets(nums);
    
    std::cout << "Subsets (power set):" << std::endl;
    for (const auto& subset : result) {
        std::cout << "[";
        for (int num : subset) {
            std::cout << num << ",";
        }
        std::cout << "]" << std::endl;
    }
    
    return 0;
}
