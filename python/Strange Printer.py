class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        
        dp = [[float('inf')] * n for _ in range(n)]

        for i in range(n):
            dp[i][i] = 1

        for length in range(2, n + 1):  
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i][j-1]  
                else:
                    for k in range(i, j):
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j])
        
        return dp[0][n - 1]
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    print(solution.strangePrinter("aaabbb"))  # Expected output: 2
    print(solution.strangePrinter("aba"))     # Expected output: 2
    print(solution.strangePrinter("abcba"))   # Expected output: 3
    print(solution.strangePrinter("a"))       # Expected output: 1
    print(solution.strangePrinter("abcabc"))  # Expected output: 5