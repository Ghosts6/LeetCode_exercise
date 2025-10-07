from typing import List

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        for i in range(len(nums) - 2):
            if nums[i] < nums[i + 1] + nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0

# Test case
if __name__ == "__main__":
    sol = Solution()

    # case 1
    nums = [2, 1, 2]
    print(f"Result of test case 1 : {sol.largestPerimeter(nums)}") # Expected 5

    # case 2
    nums2 = [1, 2, 1, 10]
    print(f"Result of test case 2 : {sol.largestPerimeter(nums2)}") # Expected 0
