class Solution:
    def countBits(self, n: int) -> list[int]:
        ans = [0] * (n + 1)
        
        for i in range(1, n + 1):
            ans[i] = ans[i >> 1] + (i & 1)
        
        return ans

# Test cases
if __name__ == "__main__":
    sol = Solution()
    print("Output 1:", sol.countBits(2))  # Output: [0, 1, 1]
    print("Output 2:", sol.countBits(5))  # Output: [0, 1, 1, 2, 1, 2]