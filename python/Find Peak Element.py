class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        
        return left

# Test cases
s = Solution()

# case 1
nums = [1, 2, 3, 1]
print(s.findPeakElement(nums))  # Output: 2

# case 2
nums = [1, 2, 1, 3, 5, 6, 4]
print(s.findPeakElement(nums))  # Output: 5 

