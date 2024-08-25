class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1] * n

        for i in range(1, m):
            for j in range(1, n):
                dp[j] = dp[j] + dp[j - 1]
        
        return dp[-1]

# Test cases
def run_tests():
    solution = Solution()

    # Test case 1: 3x7 grid
    result1 = solution.uniquePaths(3, 7)
    print("Test 1 - 3x7 Grid:", result1)  # Expected output: 28

    # Test case 2: 3x2 grid
    result2 = solution.uniquePaths(3, 2)
    print("Test 2 - 3x2 Grid:", result2)  # Expected output: 3

    # Test case 3: 10x10 grid
    result3 = solution.uniquePaths(10, 10)
    print("Test 3 - 10x10 Grid:", result3)  # Expected output: 48620


run_tests()
