from typing import List

class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n = len(s)
        total_shift = 0
        result = list(s)
        for i in range(n - 1, -1, -1):
            total_shift += shifts[i]
            result[i] = chr((ord(s[i]) - ord('a') + total_shift) % 26 + ord('a'))
        return ''.join(result)
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    s1 = "abc"
    shifts1 = [3,5,9]
    print("Out put of test case 1 :", solution.shiftingLetters(s1, shifts1)) # Expected Output: "rpl"
    # case 2
    s = "aaa"
    shifts = [1,2,3]
    print("Out put of test case 2 :", solution.shiftingLetters(s, shifts)) # Expected Output: "gfd"