class Solution:
    def countConsistentStrings(self, allowed, words):
        allowed_set = set(allowed)

        count = 0
        for word in words:
            if all(char in allowed_set for char in word):  
                count += 1
                
        return count

# Test cases
s = Solution()

# case 1
allowed1 = "ab"
words1 = ["ad", "bd", "aaab", "baa", "badab"]
print(s.countConsistentStrings(allowed1, words1))  # Expected output: 2

# case 2
allowed2 = "abc"
words2 = ["a", "b", "c", "ab", "ac", "bc", "abc"]
print(s.countConsistentStrings(allowed2, words2))  # Expected output: 7

# case 3
allowed3 = "cad"
words3 = ["cc", "acd", "b", "ba", "bac", "bad", "ac", "d"]
print(s.countConsistentStrings(allowed3, words3))  # Expected output: 4