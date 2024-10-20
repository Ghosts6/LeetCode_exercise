class Solution:
    def triangleNumber(self, nums):
        def bs(left, right, target):
            while left < right:
                mid = (left + right) // 2
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid
            return left
        
        nums.sort()
        count = 0
        
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                k = bs(j + 1, len(nums), nums[i] + nums[j])
                count += k - (j + 1)
        
        return count

# Test case
if __name__ == "__main__":
    sol = Solution()
    # case 1
    nums1 = [2, 2, 3, 4]
    print(f"Test case 1 Output: {sol.triangleNumber(nums1)}")  # Expected: 3
    
    # case 2
    nums2 = [4, 2, 3, 4]
    print(f"Test case 2 Output: {sol.triangleNumber(nums2)}")  # Expected: 4
