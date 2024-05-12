#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    void backtrack(std::vector<int>& candidates, int target, int start, std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                combination.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i, combination, result);
                combination.pop_back();
            }
        }
    }
};
// test case
int main() {
    Solution solution;
    std::vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    std::vector<std::vector<int>> result = solution.combinationSum(candidates, target);
    std::cout << "unique combinations that sum up to target:" << std::endl;
    for (const auto& combination : result) {
        std::cout << "[";
        for (int num : combination) {
            std::cout << num << ",";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
