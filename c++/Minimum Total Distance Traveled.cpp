#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

class Solution {
public:
    long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());
        
        int n = robot.size();
        int m = factory.size();

        std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1, LLONG_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= m; ++i) {
            int position = factory[i - 1][0];
            int limit = factory[i - 1][1];

            for (int j = 0; j <= n; ++j) {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);

                long long distSum = 0;
                for (int k = 1; k <= limit && j + k <= n; ++k) {
                    distSum += std::abs(static_cast<long long>(robot[j + k - 1]) - position);

                    if (dp[i - 1][j] != LLONG_MAX) {
                        dp[i][j + k] = std::min(dp[i][j + k], dp[i - 1][j] + distSum);
                    }
                }
            }
        }

        return dp[m][n];
    }
};
// Test cases
int main() {
    Solution solution;

    // case 1
    std::vector<int> robot1 = {0, 4, 6};
    std::vector<std::vector<int>> factory1 = {{2, 2}, {6, 2}};
    std::cout << "Test Case 1 Output: " << solution.minimumTotalDistance(robot1, factory1) << std::endl;

    // case 2
    std::vector<int> robot2 = {1, -1};
    std::vector<std::vector<int>> factory2 = {{-2, 1}, {2, 1}};
    std::cout << "Test Case 2 Output: " << solution.minimumTotalDistance(robot2, factory2) << std::endl;

    return 0;
}
