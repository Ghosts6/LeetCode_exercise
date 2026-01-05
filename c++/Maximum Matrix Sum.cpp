#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// optimize
class Solution {
public:
    long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;

        for (const auto& row : matrix) {
            for (int value : row) {
                int absVal = std::abs(value);
                totalSum += absVal;
                
                if (value < 0) {
                    negativeCount++;
                }
                
                if (absVal < minAbsValue) {
                    minAbsValue = absVal;
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
