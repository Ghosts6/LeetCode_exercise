from collections import Counter
from typing import List

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        count1 = Counter(word1)
        count2 = Counter(word2)
        

        if set(count1.keys()) != set(count2.keys()):
            return False

        return sorted(count1.values()) == sorted(count2.values())

# test case
if __name__ == "__main__":
    solution = Solution()
    
    # accepted case
    word1 = "abc"
    word2 = "bca"
    print("Test case 1 - Expected: True, Got:", solution.closeStrings(word1, word2))  
     
    # fail case
    word1 = "aabcc"
    word2 = "ccdee"
    print("Test case 3 - Expected: False, Got:", solution.closeStrings(word1, word2))