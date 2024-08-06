class Solution:
    def minimumPushes(self, word: str) -> int:
        total_presses = 0

        n = len(word)
        full_rows = n // 8

        remaining_letters = n % 8

        for i in range(1, full_rows + 1):
            total_presses += 8 * i

        total_presses += remaining_letters * (full_rows + 1)
        
        return total_presses

# Test case:
sol = Solution()
print(sol.minimumPushes("abcde"))  
print(sol.minimumPushes("xycdefghij"))  

