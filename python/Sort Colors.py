class Solution:
    def sortColors(self, nums):
        red, white, blue = 0, 0, len(nums) - 1
        while white <= blue:
            if nums[white] == 0:
                nums[red], nums[white] = nums[white], nums[red]
                red += 1
                white += 1
            elif nums[white] == 1:
                white += 1
            else:
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -= 1
# Test cases
if __name__ == "__main__":
    s = Solution()
    # case 1
    nums1 = [2, 0, 2, 1, 1, 0]
    s.sortColors(nums1)
    print(f"Result of test case 1 : {nums1}")  # Expected Output: [0, 0, 1, 1, 2, 2]
    # case 2
    nums2 = [2, 0, 1]
    s.sortColors(nums2)
    print(f"Result of test case 2 : {nums2}")  # Expected Output: [0, 1, 2]

