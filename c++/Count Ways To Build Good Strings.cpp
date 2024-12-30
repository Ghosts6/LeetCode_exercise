#include <iostream>
#include <vector>

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        std::vector<int> dp(high + 1, 0);
        dp[0] = 1; 

        for (int length = 1; length <= high; ++length) {
            if (length >= zero) {
                dp[length] = (dp[length] + dp[length - zero]) % MOD;
            }
            if (length >= one) {
                dp[length] = (dp[length] + dp[length - one]) % MOD;
            }
        }

        int result = 0;
        for (int length = low; length <= high; ++length) {
            result = (result + dp[length]) % MOD;
        }

        return result;
    }
};
// Test cases
int main() {
    Solution solution;

    // case 1
    int low1 = 3, high1 = 3, zero1 = 1, one1 = 1;
    std::cout << "Test Case 1 Output: " << solution.countGoodStrings(low1, high1, zero1, one1) << std::endl;

    // case 2
    int low2 = 2, high2 = 3, zero2 = 1, one2 = 2;
    std::cout << "Test Case 2 Output: " << solution.countGoodStrings(low2, high2, zero2, one2) << std::endl;

    return 0;
}