#include <iostream>
#include <vector>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                toggleRow(grid, i);
            }
        }
        for (int j = 1; j < n; ++j) {
            int countOnes = countOnesInColumn(grid, j);
            if (countOnes < m - countOnes) {
                toggleColumn(grid, j);
            }
        }
        int score = 0;
        for (int i = 0; i < m; ++i) {
            score += binaryToDecimal(grid[i]);
        }
        return score;
    }
    void toggleRow(std::vector<std::vector<int>>& grid, int row) {
        for (int j = 0; j < grid[0].size(); ++j) {
            grid[row][j] ^= 1;
        }
    }
    void toggleColumn(std::vector<std::vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); ++i) {
            grid[i][col] ^= 1;
        }
    }
    int countOnesInColumn(std::vector<std::vector<int>>& grid, int col) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            count += grid[i][col];
        }
        return count;
    }
    int binaryToDecimal(std::vector<int>& binary) {
        int decimal = 0;
        for (int i = 0; i < binary.size(); ++i) {
            decimal = decimal * 2 + binary[i];
        }
        return decimal;
    }
};
// test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    int result = solution.matrixScore(grid);
    std::cout << "highest possible score: " << result << std::endl;
    return 0;
}
