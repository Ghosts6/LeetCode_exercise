class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        left = 0
        right = 0
        max_length = 0
        zeros_count = 0
        
        while right < len(nums):
            if nums[right] == 0:
                zeros_count += 1

            while zeros_count > k:
                if nums[left] == 0:
                    zeros_count -= 1
                left += 1

            max_length = max(max_length, right - left + 1)
            right += 1
        
        return max_length

# test 
sol = Solution()
nums = [1, 1, 0, 0, 1, 1, 1, 0, 1, 1]
k = 2
print(sol.longestOnes(nums, k))