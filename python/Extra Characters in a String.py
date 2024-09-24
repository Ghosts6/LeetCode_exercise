class Solution:
    def minExtraChar(self, s: str, dictionary: list[str]) -> int:
        word_set = set(dictionary)
        n = len(s)
        
        dp = [0] * (n + 1)
        
        for i in range(n - 1, -1, -1):
            dp[i] = dp[i + 1] + 1
            
            for j in range(i + 1, n + 1):
                if s[i:j] in word_set:
                    dp[i] = min(dp[i], dp[j])
        
        return dp[0]

# Test cases 
if __name__ == "__main__":
    sol = Solution()
    # case 1
    s = "leetscode"
    dictionary = ["leet", "code", "leetcode"]
    assert sol.minExtraChar(s, dictionary) == 1, "Test case 1 failed"
    print("Test case 1 passed")

    # case 2
    s = "sayhelloworld"
    dictionary = ["hello", "world"]
    assert sol.minExtraChar(s, dictionary) == 3, "Test case 2 failed"
    print("Test case 2 passed")
