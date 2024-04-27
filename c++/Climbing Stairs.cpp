#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        std::vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// test cases
int main() {
    Solution sol;
    int n1 = 2;
    std::cout << "n = " << n1 << ", distinct ways = " << sol.climbStairs(n1) << std::endl;

    int n2 = 3;
    std::cout << "n = " << n2 << ", distinct ways = " << sol.climbStairs(n2) << std::endl;

    int n3 = 5;
    std::cout << "n = " << n3 << ", distinct ways = " << sol.climbStairs(n3) << std::endl;

    return 0;
}