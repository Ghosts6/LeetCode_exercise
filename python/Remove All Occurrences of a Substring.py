class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, "", 1)
        return s

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    s1 = "daabcbaabcbc"
    part1 = "abc"
    print(f"Test Case 1: {solution.removeOccurrences(s1, part1)}")  # Expected output: "dab"
    # case 2
    s2 = "axxxxyyyyb"
    part2 = "xy"
    print(f"Test Case 2: {solution.removeOccurrences(s2, part2)}")  # Expected output: "ab"
