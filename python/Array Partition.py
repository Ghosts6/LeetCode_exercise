class Solution:
    def arrayPairSum(self, nums):
        nums.sort()

        return sum(nums[i] for i in range(0, len(nums), 2))

# Test cases
if __name__ == "__main__":
    # case 1
    nums1 = [1, 4, 3, 2]
    result1 = Solution().arrayPairSum(nums1)
    print(f"Input: {nums1} => Output: {result1}")  # Expected output: 4

    # case 2
    nums2 = [6, 2, 6, 5, 1, 2]
    result2 = Solution().arrayPairSum(nums2)
    print(f"Input: {nums2} => Output: {result2}")  # Expected output: 9
