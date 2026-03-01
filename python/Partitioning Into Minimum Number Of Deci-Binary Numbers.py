class Solution:
    def minPartitions(self, n: str) -> int:
        """Return the minimum number of deci-binary numbers needed to sum to n."""
        max_digit = 0
        for ch in n:
            digit = ord(ch) - ord('0')
            if digit > max_digit:
                max_digit = digit
                if max_digit == 9:  # Early exit (cannot exceed 9)
                    break
        return max_digit

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    n1 = "32"
    print(f"Result of test case: {sol.minPartitions(n1)}")  # Expected: 3

    # case 2
    n2 = "82734"
    print(f"Result of test case: {sol.minPartitions(n2)}")  # Expected: 8

    # case 3 
    n3 = "27346209830709182346"
    print(f"Result of test case: {sol.minPartitions(n3)}")  # Expected: 9
