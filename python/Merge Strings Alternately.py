class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged_string = []
        len1, len2 = len(word1), len(word2)
        i, j = 0, 0
        
        while i < len1 and j < len2:
            merged_string.append(word1[i])
            merged_string.append(word2[j])
            i += 1
            j += 1
        
        while i < len1:
            merged_string.append(word1[i])
            i += 1
        
        while j < len2:
            merged_string.append(word2[j])
            j += 1
        
        return ''.join(merged_string)

# test case
solution = Solution()
word1 = "abc"
word2 = "pqr"
print(solution.mergeAlternately(word1, word2))  
