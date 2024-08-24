class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10**9 + 7

        if n == 1:
            return 1
        if n == 2:
            return 2
        if n == 3:
            return 5

        dp = [0] * (n + 1)

        dp[1], dp[2], dp[3] = 1, 2, 5

        for i in range(4, n + 1):
            dp[i] = (2 * dp[i-1] + dp[i-3]) % MOD
        
        return dp[n]

# Test cases
def run_tests():
    sol = Solution()

    # case 1
    n1 = 3
    assert sol.numTilings(n1) == 5, f"Test case 1 failed: {sol.numTilings(n1)}"

    #  case 2
    n2 = 4
    assert sol.numTilings(n2) == 11, f"Test case 2 failed: {sol.numTilings(n2)}"

    # case 3
    n3 = 5
    assert sol.numTilings(n3) == 24, f"Test case 3 failed: {sol.numTilings(n3)}"

run_tests()
