class Solution:
    def singleNonDuplicate(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = left + (right - left) // 2
            
            if mid % 2 == 1:
                mid -= 1

            if nums[mid] == nums[mid + 1]:
                left = mid + 2
            else:
                right = mid

        return nums[left]

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    nums1 = [1,1,2,3,3,4,4,8,8]
    result1 = solution.singleNonDuplicate(nums1)
    print(f"Input: {nums1} => Output: {result1}")  # Expected: 2
    
    # case 2
    nums2 = [3,3,7,7,10,11,11]
    result2 = solution.singleNonDuplicate(nums2)
    print(f"Input: {nums2} => Output: {result2}")  # Expected: 10

