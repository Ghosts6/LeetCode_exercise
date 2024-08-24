class Solution:
    def rob(self, nums):
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]

        dp = [0] * len(nums)

        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        
        return dp[-1]

#   Test cases
def run_tests():
    robber = Solution()

    #  case 1
    nums1 = [1, 2, 3, 1]
    assert robber.rob(nums1) == 4, f"Test case 1 failed: {robber.rob(nums1)}"

    # case 2
    nums2 = [2, 7, 9, 3, 1]
    assert robber.rob(nums2) == 12, f"Test case 2 failed: {robber.rob(nums2)}"

    # case 3
    nums3 = [2, 1, 1, 2]
    assert robber.rob(nums3) == 4, f"Test case 3 failed: {robber.rob(nums3)}"


    print("All test cases passed!")
run_tests()
