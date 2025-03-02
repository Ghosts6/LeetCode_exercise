class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [1] * 5
        for _ in range(n - 1):
            for j in range(3, -1, -1):
                dp[j] += dp[j + 1]
        return sum(dp)
        
# Test case
if __name__ == "__main__":
    solution = Solution()
    # case 1
    n1 = 1
    print(f"Result of test case 1 : {solution.countVowelStrings(n1)}") # Expected Output: 5

    # case 2
    n2 = 2
    print(f"Result of test case 2 : {solution.countVowelStrings(n2)}") # Expected Output: 15

    # case 3
    n3 = 33
    print(f"Result of test case 3 : {solution.countVowelStrings(n3)}") # Expected Output: 66045