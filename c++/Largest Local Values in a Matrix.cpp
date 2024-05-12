#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> maxLocal(n - 2, std::vector<int>(n - 2, 0));

        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int maxVal = grid[i][j];
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        maxVal = std::max(maxVal, grid[i + di][j + dj]);
                    }
                }
                maxLocal[i - 1][j - 1] = maxVal;
            }
        }
        return maxLocal;
    }
};
// test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<std::vector<int>> maxLocal = solution.largestLocal(grid);
    std::cout << "result of test case :" << std::endl;
    for (const auto& row : maxLocal) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
