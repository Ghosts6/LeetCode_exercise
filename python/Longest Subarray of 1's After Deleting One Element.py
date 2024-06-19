from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left = 0
        right = 0
        max_length = 0
        zero_count = 0

        while right < len(nums):
            if nums[right] == 0:
                zero_count += 1

            while zero_count > 1:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1

            max_length = max(max_length, right - left)
            right += 1

        return max_length

# test case
if __name__ == "__main__":
    solution = Solution()
    
    nums = [1, 1, 0, 1, 1, 1]
    result = solution.longestSubarray(nums)
    print(f"result of test case : {result}") 
