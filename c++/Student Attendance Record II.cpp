#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        std::vector<std::vector<std::vector<long long>>> dp(n + 1, std::vector<std::vector<long long>>(2, std::vector<long long>(3, 0)));    
        dp[0][0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }

            for (int k = 0; k < 3; ++k) {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }

            for (int j = 0; j < 2; ++j) {
                for (int k = 1; k < 3; ++k) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }

        long long result = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                result = (result + dp[n][j][k]) % MOD;
            }
        }

        return result;
    }
};
//  test case
int main() {
    Solution solution;

    int test1 = 2;
    int test2 = 1;
    int test3 = 10101;

    std::cout << "Test 1: " << solution.checkRecord(test1) << " (expected: 8)" << std::endl;
    std::cout << "Test 2: " << solution.checkRecord(test2) << " (expected: 3)" << std::endl;
    std::cout << "Test 3: " << solution.checkRecord(test3) << " (expected: <very large number>)" << std::endl;

    return 0;
}
