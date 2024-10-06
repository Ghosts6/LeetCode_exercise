class Solution:
    def findMin(self, nums):
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] > nums[right]: 
                left = mid + 1
            elif nums[mid] < nums[right]:  
                right = mid
            else:  
                right -= 1

        return nums[left]

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    nums1 = [1, 3, 5]
    result1 = solution.findMin(nums1)
    print("Test Case 1 Output:", result1)  # Expected output: 1

    # case 2
    nums2 = [2, 2, 2, 0, 1]
    result2 = solution.findMin(nums2)
    print("Test Case 2 Output:", result2)  # Expected output: 0
