#include <iostream>
#include <vector>

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = std::min(std::min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
                }
                count += matrix[i][j];
            }
        }

        return count;
    }
};
// Test cases
int main() {
    Solution solution;

    // case 1
    std::vector<std::vector<int>> matrix1 = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    std::cout << "Output for Test Case 1: " << solution.countSquares(matrix1) << std::endl; // Expected output: 15

    // case 2
    std::vector<std::vector<int>> matrix2 = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    std::cout << "Output for Test Case 2: " << solution.countSquares(matrix2) << std::endl; // Expected output: 7

    return 0;
}
