class Solution:
    def longestSubarray(self, nums):
        max_val = max(nums)

        max_length = 0
        current_length = 0

        for num in nums:
            if num == max_val:
                current_length += 1
                max_length = max(max_length, current_length)
            else:
                current_length = 0
        
        return max_length

# Test cases 
if __name__ == "__main__":
    #  case 1
    nums1 = [1, 2, 3, 3, 2, 2]
    solution = Solution()
    print(f"Test case 1 result: {solution.longestSubarray(nums1)}")  # Output: 2

    # case 2
    nums2 = [1, 2, 3, 4]
    print(f"Test case 2 result: {solution.longestSubarray(nums2)}")  # Output: 1

    # case 3 
    nums3 = [5, 5, 5, 5, 5]
    print(f"Test case 3 result: {solution.longestSubarray(nums3)}")  # Output: 5

    # case 4 
    nums4 = [7]
    print(f"Test case 4 result: {solution.longestSubarray(nums4)}")  # Output: 1
