from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str):
        words_s1 = s1.split()
        words_s2 = s2.split()
        
        word_count = Counter(words_s1 + words_s2)
        
        return [word for word, count in word_count.items() if count == 1]

# Test cases
if __name__ == "__main__":
    sol = Solution()

    #  case 1
    s1 = "this apple is sweet"
    s2 = "this apple is sour"
    print(sol.uncommonFromSentences(s1, s2))  # Expected output: ["sweet", "sour"]

    #  case 2
    s1 = "apple apple"
    s2 = "banana"
    print(sol.uncommonFromSentences(s1, s2))  # Expected output: ["banana"]

    # Additional test case
    s1 = "a b c"
    s2 = "a d e"
    print(sol.uncommonFromSentences(s1, s2))  # Expected output: ["b", "c", "d", "e"]
