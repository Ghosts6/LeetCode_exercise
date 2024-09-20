class Solution:
    def shortestPalindrome(self, s: str) -> str:
        temp = s + "#" + s[::-1]
      
        n = len(temp)
        lps = [0] * n

        for i in range(1, n):
            j = lps[i - 1]
            while j > 0 and temp[i] != temp[j]:
                j = lps[j - 1]
            if temp[i] == temp[j]:
                j += 1
            lps[i] = j
          
        longest_palindromic_prefix = lps[-1]

        to_add = s[longest_palindromic_prefix:][::-1]
        
        return to_add + s

# Test cases
solution = Solution()

#  Case 1
s1 = "aacecaaa"
print(f"Input: {s1}, Output: {solution.shortestPalindrome(s1)}") # Expected: "aaacecaaa"

#  Case 2
s2 = "abcd"
print(f"Input: {s2}, Output: {solution.shortestPalindrome(s2)}") # Expected: "dcbabcd"
