from typing import List
from collections import Counter

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        """
        Returns the length of the longest palindrome that can be built by 
        concatenating selected words from the list.
        """
        count = Counter(words)
        length = 0
        used_middle = False

        for word in count:
            rev = word[::-1]
            if word == rev:
                pairs = count[word] // 2
                length += pairs * 4
                count[word] -= pairs * 2
                if not used_middle and count[word] > 0:
                    length += 2
                    used_middle = True
            elif word < rev:
                pairs = min(count[word], count[rev])
                length += pairs * 4

        return length

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    print(solution.longestPalindrome(["lc", "cl", "gg"]))  # Expected Output: 6
    # case 2
    print(solution.longestPalindrome(["ab", "ty", "yt", "lc", "cl", "ab"]))  # Expected Output: 8
    # case 3
    print(solution.longestPalindrome(["cc", "ll", "xx"]))  # Expected Output: 2

