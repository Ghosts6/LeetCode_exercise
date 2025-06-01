from math import comb

class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        total = 0
        for x in range(4):
            sign = (-1) ** x
            ways = comb(3, x)
            remaining = n - x * (limit + 1)
            if remaining >= 0:
                ways *= comb(remaining + 2, 2)
                total += sign * ways
        return total
# Test cases
if __name__ == "__main__":
    solution = Solution()
    print(f"Result of test case 1: ", solution.distributeCandies(5, 2))  # Output: 3
    print(f"Result of test case 2: ", solution.distributeCandies(3, 3))  # Output: 10
