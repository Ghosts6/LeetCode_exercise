class Solution:
    """Count fair pairs with sum in [lower, upper]."""
    def countFairPairs(self, nums, lower, upper):
        nums.sort()
        count = 0
        n = len(nums)

        def lower_bound(arr, target, start):
            l, r = start, len(arr)
            while l < r:
                m = (l + r) // 2
                if arr[m] < target:
                    l = m + 1
                else:
                    r = m
            return l

        def upper_bound(arr, target, start):
            l, r = start, len(arr)
            while l < r:
                m = (l + r) // 2
                if arr[m] <= target:
                    l = m + 1
                else:
                    r = m
            return l

        for i in range(n):
            left = lower - nums[i]
            right = upper - nums[i]
            l = lower_bound(nums, left, i + 1)
            r = upper_bound(nums, right, i + 1)
            count += r - l
        return count
      
# Test cases
if __name__ == "__main__":
    solution = Solution()
  
    # case 1
    print(f"Test 1: {solution.countFairPairs([1,2,3,4,5], 3, 6)}")
  
    # case 2
    print(f"Test 2: {solution.countFairPairs([0,1,7,4,4,5], 3, 6)}")
  
    # case 3
    print(f"Test 3: {solution.countFairPairs([1,1,1,1], 2, 2)}")
