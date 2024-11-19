class Solution:
    def maximumSubarraySum(self, nums, k):
        n = len(nums)
        if n < k:
            return 0
        
        current_sum = sum(nums[:k])
        max_sum = 0
        window_map = {}

        for i in range(k):
            window_map[nums[i]] = window_map.get(nums[i], 0) + 1
        
        if len(window_map) == k:
            max_sum = current_sum
        
        for i in range(k, n):
            window_map[nums[i - k]] -= 1
            if window_map[nums[i - k]] == 0:
                del window_map[nums[i - k]]

            window_map[nums[i]] = window_map.get(nums[i], 0) + 1

            if len(window_map) == k:
                current_sum -= nums[i - k]
                current_sum += nums[i]
                max_sum = max(max_sum, current_sum)

        return max_sum if max_sum != 0 else 0
# Test cases
if __name__ == "__main__":
    solution = Solution()

    # Case 1
    nums1 = [1, 5, 4, 2, 9, 9, 9]
    k1 = 3
    print(solution.maximumSubarraySum(nums1, k1))  # Expected Output: 15

    # Case 2
    nums2 = [4, 4, 4]
    k2 = 3
    print(solution.maximumSubarraySum(nums2, k2))  # Expected Output: 0
