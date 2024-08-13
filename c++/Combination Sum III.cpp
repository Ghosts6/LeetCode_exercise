#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        backtrack(k, n, 1, combination, result);
        return result;
    }

private:
    void backtrack(int k, int target, int start, std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (target == 0 && combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > target) {
                break;
            }

            combination.push_back(i);
            backtrack(k, target - i, i + 1, combination, result);
            combination.pop_back();
        }
    }
};
//  tets cases
int main() {
    Solution solution;
    
    // case 1
    int k1 = 3, n1 = 7;
    std::vector<std::vector<int>> result1 = solution.combinationSum3(k1, n1);
    
    std::cout << "Test case 1 results (k=3, n=7):\n";
    for (const auto& comb : result1) {
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    // case 2
    int k2 = 3, n2 = 9;
    std::vector<std::vector<int>> result2 = solution.combinationSum3(k2, n2);
    
    std::cout << "Test case 2 results (k=3, n=9):\n";
    for (const auto& comb : result2) {
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
