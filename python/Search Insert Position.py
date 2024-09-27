class Solution:
    def searchInsert(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left
   
# Test cases
sol = Solution()
# case 1 
nums = [1, 3, 5, 6]
target = 5
print(sol.searchInsert(nums, target))  # Output: 2
# case 2
nums = [1, 3, 5, 6]
target = 2
print(sol.searchInsert(nums, target))  # Output: 1