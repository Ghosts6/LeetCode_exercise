class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        """Return the minimum XOR among all valid paths."""
        m, n = len(grid), len(grid[0])
        dp = [[set() for _ in range(n)] for _ in range(m)]
        dp[0][0].add(grid[0][0])

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                value = grid[i][j]

                if i > 0:
                    dp[i][j].update(x ^ value for x in dp[i - 1][j])

                if j > 0:
                    dp[i][j].update(x ^ value for x in dp[i][j - 1])

        return min(dp[m - 1][n - 1])

# Test case
if __name__ == "__main__":
    sol = Solution()

    # case 1
    grid1 = [[1,2],[3,4]]
    print(f"Result of test case 1 : {sol.minCost(grid1)}") # Expected: 6
    
    # case 2
    grid2 = [[6,7],[5,8]]
    print(f"Result of test case 2 : {sol.minCost(grid2)}") # Expected: 9
    
    # case 3
    grid3 = [[2,7,5]]
    print(f"Result of test case 3 : {sol.minCost(grid3)}") # Expected: 0
