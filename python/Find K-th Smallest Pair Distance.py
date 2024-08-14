class Solution:
    def smallestDistancePair(self, nums: list[int], k: int) -> int:
        def count_pairs(nums, mid):
            count = 0
            left = 0
            for right in range(len(nums)):
                while nums[right] - nums[left] > mid:
                    left += 1
                count += right - left
            return count
        
        nums.sort()
        low, high = 0, nums[-1] - nums[0]
        
        while low < high:
            mid = (low + high) // 2
            if count_pairs(nums, mid) < k:
                low = mid + 1
            else:
                high = mid
        
        return low

# Test cases
s = Solution()

# case 1
nums = [1, 3, 1]
k = 1
print(s.smallestDistancePair(nums, k))  # Output: 0

# case 2
nums = [1, 1, 1]
k = 2
print(s.smallestDistancePair(nums, k))  # Output: 0

# case 3
nums = [1, 6, 1]
k = 3
print(s.smallestDistancePair(nums, k))  # Output: 5
