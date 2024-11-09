class Solution:
    def minEnd(self, n: int, x: int) -> int:
        last_element = x
        steps_remaining = n - 1
        bit_shift = 1

        while steps_remaining > 0:
            if (x & bit_shift) == 0:
                last_element |= (steps_remaining & 1) * bit_shift
                steps_remaining >>= 1
            bit_shift <<= 1

        return last_element

# Test cases
if __name__ == "__main__":
    # case 1
    n = 3
    x = 4
    result = Solution().minEnd(n, x)
    print(f"Output for n = {n}, x = {x}: {result}")  # Expected Output: 6

    # case 2
    n = 2
    x = 7
    result = Solution().minEnd(n, x)
    print(f"Output for n = {n}, x = {x}: {result}")  # Expected Output: 15