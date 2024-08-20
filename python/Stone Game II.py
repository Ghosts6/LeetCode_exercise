class Solution:
    def stoneGameII(self, piles):
        n = len(piles)
        prefix_sum = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            prefix_sum[i] = prefix_sum[i + 1] + piles[i]

        dp = [[0] * (n + 1) for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for m in range(1, n + 1):
                max_stones = 0

                for x in range(1, 2 * m + 1):
                    if i + x > n:
                        break  
                    if i + x == n:
                        max_stones = max(max_stones, prefix_sum[i])
                    else:
                        max_stones = max(max_stones, prefix_sum[i] - dp[i + x][max(m, x)])
                dp[i][m] = max_stones
        
        return dp[0][1]

# Test Case
solution = Solution()
piles = [2, 7, 9, 4, 4]
print(solution.stoneGameII(piles))