#include <iostream>
#include <vector>
#include <algorithm> 

class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = std::min(rowSum[i], colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }

        return matrix;
    }
};

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
// test case
int main() {
    std::vector<int> rowSum = {3, 8};
    std::vector<int> colSum = {4, 7};

    Solution sol;
    std::vector<std::vector<int>> result = sol.restoreMatrix(rowSum, colSum);

    std::cout << "Resulting Matrix:" << std::endl;
    printMatrix(result);

    return 0;
}
