#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j != k) {
                        dp[i][j] = std::min(dp[i][j], grid[i][j] + dp[i - 1][k]);
                    }
                }
            }
        }
        return *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// test case
int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int result = sol.minFallingPathSum(grid);
    std::cout<<"result :"<<result<<std::endl;
    return 0;
}
