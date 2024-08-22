class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        t0, t1, t2 = 0, 1, 1
        for i in range(3, n + 1):
            tn = t0 + t1 + t2
            t0, t1, t2 = t1, t2, tn
        return t2

# Test cases
if __name__ == "__main__":
    solution = Solution()
    print(solution.tribonacci(4))  # Output: 4
    print(solution.tribonacci(25)) # Output: 1389537