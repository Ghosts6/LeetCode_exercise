from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Merges nums2 into nums1 as a sorted array in-place.
        """
        i, j, k = m - 1, n - 1, m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # Test Case 1
    nums1_1 = [1]
    m1 = 1
    nums2_1 = []
    n1 = 0
    solution.merge(nums1_1, m1, nums2_1, n1)
    print(f"Result of Test Case 1: {nums1_1}")  # Expected: [1]

    # Test Case 2
    nums1_2 = [0]
    m2 = 0
    nums2_2 = [1]
    n2 = 1
    solution.merge(nums1_2, m2, nums2_2, n2)
    print(f"Result of Test Case 2: {nums1_2}")  # Expected: [1]

    # Test Case 3
    nums1_3 = [1, 2, 3, 0, 0, 0]
    m3 = 3
    nums2_3 = [2, 5, 6]
    n3 = 3
    solution.merge(nums1_3, m3, nums2_3, n3)
    print(f"Result of Test Case 3: {nums1_3}")  # Expected: [1, 2, 2, 3, 5, 6]

