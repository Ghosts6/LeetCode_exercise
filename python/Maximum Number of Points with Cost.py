class Solution:
    def maxPoints(self, points):
        m, n = len(points), len(points[0])

        dp = points[0][:]
        
        for r in range(1, m):
            new_dp = [0] * n
 
            left_dp = [0] * n
            left_dp[0] = dp[0]
            for c in range(1, n):
                left_dp[c] = max(left_dp[c-1] - 1, dp[c])

            right_dp = [0] * n
            right_dp[n-1] = dp[n-1]
            for c in range(n-2, -1, -1):
                right_dp[c] = max(right_dp[c+1] - 1, dp[c])

            for c in range(n):
                new_dp[c] = max(left_dp[c], right_dp[c]) + points[r][c]
            
            dp = new_dp
        
        return max(dp)

# Test Case
points = [[1,2,3],[1,5,1],[3,1,1]]
solution = Solution()
print(solution.maxPoints(points))  
