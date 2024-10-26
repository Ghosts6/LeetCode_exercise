class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        half_len = (m + n + 1) // 2
        
        left, right = 0, m
        while left <= right:
            i = (left + right) // 2
            j = half_len - i
            
            nums1_left_max = nums1[i - 1] if i > 0 else float('-inf')
            nums1_right_min = nums1[i] if i < m else float('inf')
            nums2_left_max = nums2[j - 1] if j > 0 else float('-inf')
            nums2_right_min = nums2[j] if j < n else float('inf')
            
            if nums1_left_max <= nums2_right_min and nums2_left_max <= nums1_right_min:
                if (m + n) % 2 == 1:
                    return max(nums1_left_max, nums2_left_max)
                return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2
            elif nums1_left_max > nums2_right_min:
                right = i - 1
            else:
                left = i + 1
        
        raise ValueError("The arrays are not sorted or input is invalid.")

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    nums1 = [1, 3]
    nums2 = [2]
    print("Test Case 1 Result:", solution.findMedianSortedArrays(nums1, nums2))  # Expected output: 2.00000
    
    # Test case 2
    nums1 = [1, 2]
    nums2 = [3, 4]
    print("Test Case 2 Result:", solution.findMedianSortedArrays(nums1, nums2))  # Expected output: 2.50000

