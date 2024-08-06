class Solution:
    def minimumPushes(self, input_text: str) -> int:
        from collections import Counter

        letter_counts = Counter(input_text)

        sorted_counts = sorted(letter_counts.values(), reverse=True)

        total_key_presses = 0

        for index, count in enumerate(sorted_counts):
            total_key_presses += (index // 8 + 1) * count
        
        return total_key_presses

# Test cases
solution = Solution()
# first case Output: 6
test_word = "hello"
print(f"Minimum keypresses needed for '{test_word}': {solution.minimumPushes(test_word)}")  
# second case Output: 15
test_word = "aaaabbbbccccddddeeee"
print(f"Minimum keypresses needed for '{test_word}': {solution.minimumPushes(test_word)}")  
# fail case Output: 24
test_word = "aabbccddeeffgghhiiiiii"
print(f"Minimum keypresses needed for '{test_word}': {solution.minimumPushes(test_word)}") 