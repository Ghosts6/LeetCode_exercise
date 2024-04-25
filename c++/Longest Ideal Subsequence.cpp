#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int longestIdealString(std::string s, int k) {
        int dp[26] = {0};
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char cc = s[i];
            int idx = cc - 'a';
            int maxi = INT_MIN;

            int left = std::max((idx - k), 0);
            int right = std::min((idx + k), 25);

            for (int j = left; j <= right; j++) {
                maxi = std::max(maxi, dp[j]);
            }

            dp[idx] = maxi + 1;
        }

        int maxLen = INT_MIN;
        for (int i = 0; i < 26; i++) {
            maxLen = std::max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

// test case
int main() {
    Solution sol;
    std::string s = "abcde";
    int k = 1;
    int result = sol.longestIdealString(s, k);
    std::cout << "result: " << result << std::endl;
    return 0;
}