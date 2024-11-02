class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split()

        if len(words) == 1:
            return words[0][0] == words[0][-1]

        for i in range(len(words)):
            current_word_last_char = words[i][-1]
            next_word_first_char = words[(i + 1) % len(words)][0]
            if current_word_last_char != next_word_first_char:
                return False
        
        return True
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    print(solution.isCircularSentence("leetcode exercises sound delightful"))  # Expected output: True

    # case 2
    print(solution.isCircularSentence("eetcode"))  # Expected output: True

    # case 3
    print(solution.isCircularSentence("Leetcode is cool"))  # Expected output: False

