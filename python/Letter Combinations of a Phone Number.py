from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        mapping = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        result = []
        self.backtrack(digits, mapping, 0, "", result)
        return result

    def backtrack(self, digits: str, mapping: List[str], index: int, current: str, result: List[str]):
        if index == len(digits):
            result.append(current)
            return

        digit = int(digits[index])
        letters = mapping[digit]

        for letter in letters:
            self.backtrack(digits, mapping, index + 1, current + letter, result)

# Test Cases
if __name__ == "__main__":
    solution = Solution()
    # Test case 1: digits = "23"
    print("Test case 1 - digits = '23':", solution.letterCombinations("23"))

    # Test case 2: digits = ""
    print("Test case 2 - digits = '':", solution.letterCombinations(""))

    # Test case 3: digits = "2"
    print("Test case 3 - digits = '2':", solution.letterCombinations("2"))
