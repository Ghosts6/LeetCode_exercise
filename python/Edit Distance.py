class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)

        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):

                if i == 0:
                    dp[i][j] = j 

                elif j == 0:
                    dp[i][j] = i  

                elif word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]

                else:
                    dp[i][j] = 1 + min(dp[i - 1][j],    
                                       dp[i][j - 1],    
                                       dp[i - 1][j - 1])  

        return dp[m][n]


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    word1 = "horse"
    word2 = "ros"
    print(f"Edit Distance between '{word1}' and '{word2}': {solution.minDistance(word1, word2)}")  # Output: 3

    #  case 2
    word1 = "intention"
    word2 = "execution"
    print(f"Edit Distance between '{word1}' and '{word2}': {solution.minDistance(word1, word2)}")  # Output: 5

    # Additional case
    word1 = "abc"
    word2 = "yabd"
    print(f"Edit Distance between '{word1}' and '{word2}': {solution.minDistance(word1, word2)}")  # Output: 2
