#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> maxRow(n, 0);
        std::vector<int> maxCol(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                maxRow[i] = std::max(maxRow[i], grid[i][j]);
                maxCol[j] = std::max(maxCol[j], grid[i][j]);
            }
        }
        int maxIncrease = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                maxIncrease += std::min(maxRow[i], maxCol[j]) - grid[i][j];
            }
        }
        return maxIncrease;
    }
};
// test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0}
    };
    int maxIncrease = solution.maxIncreaseKeepingSkyline(grid);
    std::cout << "result of test case: " << maxIncrease << std::endl;
    return 0;
}
