class Solution:
    def numSubseq(self, nums, target):
        MOD = 10**9 + 7
        nums.sort()
        
        n = len(nums)
        power_of_two = [1] * n
        for i in range(1, n):
            power_of_two[i] = power_of_two[i - 1] * 2 % MOD
        
        left, right = 0, n - 1
        result = 0

        while left <= right:
            if nums[left] + nums[right] <= target:
                result = (result + power_of_two[right - left]) % MOD
                left += 1
            else:
                right -= 1
        
        return result

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    nums1 = [3, 5, 6, 7]
    target1 = 9
    print(solution.numSubseq(nums1, target1))  # Output: 4

    # case 2
    nums2 = [3, 3, 6, 8]
    target2 = 10
    print(solution.numSubseq(nums2, target2))  # Output: 6

    # case 3
    nums3 = [2, 3, 3, 4, 6, 7]
    target3 = 12
    print(solution.numSubseq(nums3, target3))  # Output: 61
