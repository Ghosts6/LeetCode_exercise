#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }
private:
    void backtrack(int n, int k, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i) {
            current.push_back(i);
            backtrack(n, k, i + 1, current, result);
            current.pop_back();
        }
    }
};

// test cases
int main() {
    Solution sol;
    int n = 4, k = 2;
    std::vector<std::vector<int>> result = sol.combine(n, k);
    std::cout << "Combinations of " << k << " numbers chosen from the range [1, " << n << "]:" << std::endl;
    for (const auto& comb : result) {
        std::cout << "[ ";
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}