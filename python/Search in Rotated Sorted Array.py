class Solution:
    def search(self, nums, target):
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
 
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        
        return -1

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    nums1 = [4, 5, 6, 7, 0, 1, 2]
    target1 = 0
    print(f"Test case 1: {sol.search(nums1, target1)}")  # Expected output: 4

    # case 2
    nums2 = [4, 5, 6, 7, 0, 1, 2]
    target2 = 3
    print(f"Test case 2: {sol.search(nums2, target2)}")  # Expected output: -1

    # case 3
    nums3 = [1, 2, 3, 4, 5, 6, 7]
    target3 = 5
    print(f"Test case 3: {sol.search(nums3, target3)}")  # Expected output: 4

