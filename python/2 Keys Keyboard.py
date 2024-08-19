class Solution:
    def minSteps(self, n: int) -> int:
        dp = [float('inf')] * (n + 1)
        dp[1] = 0  
        
        for i in range(2, n + 1):
            for j in range(1, i // 2 + 1):
                if i % j == 0:
                    dp[i] = min(dp[i], dp[j] + (i // j))
        
        return dp[n]
    
solution = Solution()

# Test cases
print("Test case 1 - n = 3:", solution.minSteps(3))

print("Test case 2 - n = 1:", solution.minSteps(1))

print("Test case 3 - n = 6:", solution.minSteps(6))

print("Test case 4 - n = 9:", solution.minSteps(9))

