#include <iostream>
#include <vector>

class Solution {
public:
    int rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                std::swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        return n;
    }
};
// test case
int main() {
    Solution sol;
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = sol.rotate(matrix);
    return 0;
}
