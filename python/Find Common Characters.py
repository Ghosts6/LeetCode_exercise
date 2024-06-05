from typing import List

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:

        min_freq = [float('inf')] * 26
        base_count = [0] * 26

        for char in words[0]:
            base_count[ord(char) - ord('a')] += 1

        for i in range(26):
            min_freq[i] = base_count[i]

        for word in words[1:]:
            char_count = [0] * 26
            for char in word:
                char_count[ord(char) - ord('a')] += 1

            for i in range(26):
                min_freq[i] = min(min_freq[i], char_count[i])


        result = []
        for i in range(26):
            result.extend([chr(i + ord('a'))] * min_freq[i])
        
        return result

# test case
if __name__ == "__main__":
    sol = Solution()
    words = ["bella", "label", "roller"]
    print(sol.commonChars(words)) 
