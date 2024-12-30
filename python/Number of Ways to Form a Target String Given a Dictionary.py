from collections import Counter
from functools import lru_cache

class Solution:
    def numWays(self, words, target):
        MOD = 10**9 + 7
        m, n = len(target), len(words[0])

        freq = [Counter() for _ in range(n)]
        for word in words:
            for i, char in enumerate(word):
                freq[i][char] += 1

        @lru_cache(None)
        def dp(i, j):
            if i == m:  
                return 1
            if j == n:  
                return 0

            ways = dp(i, j + 1)

            if target[i] in freq[j]:
                ways += freq[j][target[i]] * dp(i + 1, j + 1)
                ways %= MOD

            return ways

        return dp(0, 0)
# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    words1 = ["acca","bbbb","caca"]
    target1 = "aba"
    print("Test case 1 output:",solution.numWays(words1 , target1)) # Expected Output: 6

    # case 2
    words2 = ["abba","baab"]
    target2 = "bab"
    print("Test case 2 output:",solution.numWays(words2 , target2)) # Expected Output: 4