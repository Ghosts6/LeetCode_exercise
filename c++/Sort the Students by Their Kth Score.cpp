#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>>& score, int k) {
        std::sort(score.begin(), score.end(), [&](const std::vector<int>& a, const std::vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<std::vector<int>> score = {{70, 85, 90}, {80, 95, 70}, {60, 75, 80}};
    int k = 1;
    auto result = sol.sortTheStudents(score, k);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
