from typing import List
from collections import defaultdict

class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        prev_max = float('-inf')
        current_min = current_max = nums[0]
        prev_bit_count = nums[0].bit_count()

        for num in nums:
            bit_count = num.bit_count()

            if bit_count == prev_bit_count:
                current_min = min(current_min, num)
                current_max = max(current_max, num)
            else:
                if current_min < prev_max:
                    return False
                prev_max = current_max
                current_min = current_max = num
                prev_bit_count = bit_count

        return current_min >= prev_max
# Test cases
if __name__ == "__main__":
    # case 1
    nums1 = [8, 4, 2, 30, 15]
    solution = Solution()
    print("Test Case 1 - Expected: True, Got:", solution.canSortArray(nums1))  # True

    # case 2
    nums2 = [1, 2, 3, 4, 5]
    print("Test Case 2 - Expected: True, Got:", solution.canSortArray(nums2))  # True

    # Additional cases
    nums3 = [10, 7, 12, 3, 6]
    print("Test Case 3 - Expected: False, Got:", solution.canSortArray(nums3))  # False
