class Solution:
    def minChanges(self, s: str) -> int:
        """Minimum number of changes using a for loop"""
        result = 0

        for i in range(0, len(s), 2):
            if s[i] != s[i + 1]:
                result += 1

        return result

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    s1 = "1001"
    print(f"Result of test case 1 : {sol.minChanges(s1)}") # Expected: 2

    # case 2
    s2 = "10"
    print(f"Result of test case 2 : {sol.minChanges(s2)}") # Expected: 1

    # case 3
    s3 = "0000"
    print(f"Result of test case 3 : {sol.minChanges(s3)}") # Expected: 0
