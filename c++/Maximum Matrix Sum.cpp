#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = matrix[i][j];
                totalSum += static_cast<long long>(abs(value));
                minAbsValue = std::min(minAbsValue, abs(value));
                if (value < 0) {
                    negativeCount++;
                }
            }
        }

        if (negativeCount % 2 != 0) {
            totalSum -= 2LL * minAbsValue;
        }

        return totalSum;
    }
};
// Test cases
int main() {
    Solution solution;

    // case 1
    std::vector<std::vector<int>> matrix1 = {{1, -1}, {-1, 1}};
    std::cout << "Test Case 1 Output: " << solution.maxMatrixSum(matrix1) << std::endl;

    // case 2
    std::vector<std::vector<int>> matrix2 = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    std::cout << "Test Case 2 Output: " << solution.maxMatrixSum(matrix2) << std::endl;

    return 0;
}
