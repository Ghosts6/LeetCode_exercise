#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, int start, std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break; 
            }

            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            combination.pop_back();
        }
    }
};
//  tets cases
int main() {
    Solution solution;
    
    // case 1
    std::vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    std::vector<std::vector<int>> result1 = solution.combinationSum2(candidates1, target1);
    
    std::cout << "Test case 1 results:\n";
    for (const auto& comb : result1) {
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    // case 2
    std::vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    std::vector<std::vector<int>> result2 = solution.combinationSum2(candidates2, target2);
    
    std::cout << "Test case 2 results:\n";
    for (const auto& comb : result2) {
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
