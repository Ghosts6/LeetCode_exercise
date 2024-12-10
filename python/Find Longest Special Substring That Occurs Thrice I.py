class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        longest = -1

        for length in range(1, n + 1):
            frequency = {}
            for i in range(n - length + 1):
                substring = s[i:i + length]
                if all(char == substring[0] for char in substring):
                    frequency[substring] = frequency.get(substring, 0) + 1
                    if frequency[substring] >= 3:
                        longest = max(longest, length)

        return longest
# Test cases
if __name__ == "__main__":
    solution = Solution()  
    # case 1
    s1 = "aaaa"
    print("Test case 1:", solution.maximumLength(s1))  # Output: 2
    
    # case 2
    s2 = "abcdef"
    print("Test case 2:", solution.maximumLength(s2))  # Output: -1
    
    # case 3
    s3 = "abcaba"
    print("Test case 3:", solution.maximumLength(s3))  # Output: 1
