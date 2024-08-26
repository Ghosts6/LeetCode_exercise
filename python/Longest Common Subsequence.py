class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]

# Test Cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    text1 = "abcde"
    text2 = "ace"
    print("Test Case 1: ", solution.longestCommonSubsequence(text1, text2))  # Output: 3

    # case 2
    text1 = "abc"
    text2 = "abc"
    print("Test Case 2: ", solution.longestCommonSubsequence(text1, text2))  # Output: 3

    # case 3: No common subsequence
    text1 = "abc"
    text2 = "def"
    print("Test Case 3: ", solution.longestCommonSubsequence(text1, text2))  # Output: 0

    # case 4: One string is empty
    text1 = ""
    text2 = "abc"
    print("Test Case 4: ", solution.longestCommonSubsequence(text1, text2))  # Output: 0

    # case 5: Both strings are empty
    text1 = ""
    text2 = ""
    print("Test Case 5: ", solution.longestCommonSubsequence(text1, text2))  # Output: 0
