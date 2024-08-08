#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            ++top;

            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            --right;

            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                --bottom;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                ++left;
            }
        }
        return matrix;
    }
};

int main() {
    int n = 4;
    Solution sm;
    std::vector<std::vector<int>> result = sm.generateMatrix(n);

    for (const auto& row : result) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
