class Solution:
    def findMin(self, nums):
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return nums[left]

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    nums1 = [3, 4, 5, 1, 2]
    print(f"Test case 1: Minimum of {nums1} is {solution.findMin(nums1)}")  # Output: 1

    # case 2
    nums2 = [4, 5, 6, 7, 0, 1, 2]
    print(f"Test case 2: Minimum of {nums2} is {solution.findMin(nums2)}")  # Output: 0

    # case 3
    nums3 = [11, 13, 15, 17]
    print(f"Test case 3: Minimum of {nums3} is {solution.findMin(nums3)}")  # Output: 11
