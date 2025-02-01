class Solution:
    def isArraySpecial(self, nums):
        return all((nums[i] % 2) != (nums[i + 1] % 2) for i in range(len(nums) - 1))

# Test cases
if __name__ == "__main__":
    solution = Solution()
    print(solution.isArraySpecial([1]))  # Expected Output: True
    print(solution.isArraySpecial([2, 1, 4]))  # Expected Output: True
    print(solution.isArraySpecial([4, 3, 1, 6]))  # Expected Output: False
