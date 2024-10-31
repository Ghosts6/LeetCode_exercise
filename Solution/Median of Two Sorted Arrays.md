### 📜 Median of Two Sorted Arrays

### 💡 Intuition
1. To find the median of two sorted arrays, we need a way to partition the arrays such that all elements on the left side of the partition are smaller than those on the right.
2. By focusing on the shorter array (for efficiency), we use **binary search** to find a position where the largest left-side element is less than or equal to the smallest right-side element.
3. With the arrays correctly partitioned, we can easily calculate the median based on whether the total length of both arrays is even or odd.
4. **Binary search** lets us narrow down to the correct partition in `O(log(min(m, n)))` time, where `m` and `n` are the lengths of the two arrays.

### 🛠️ Approach
1. Start with two pointers, `left` and `right`, on the shorter array (nums1).
2. For each midpoint `i` of `nums1`, calculate `j`, the corresponding partition in `nums2`, so the left and right sides balance out.
3. Check if the largest left-side element of both partitions is less than or equal to the smallest right-side element.
   - If true, calculate the median directly.
   - If not, adjust `left` and `right` to refine the partition until the condition is met.

### ⏰ Complexity
- **Time complexity**: `O(log(min(m, n)))`, thanks to binary search on the smaller array.
- **Space complexity**: `O(1)`, since we use a constant amount of extra space.

## 💻 Code
```Python3 []
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
```
```C++ []
class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int half_len = (m + n + 1) / 2;

        int left = 0, right = m;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = half_len - i;

            int nums1_left_max = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right_min = (i == m) ? INT_MAX : nums1[i];
            int nums2_left_max = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right_min = (j == n) ? INT_MAX : nums2[j];

            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                if ((m + n) % 2 == 1) {
                    return std::max(nums1_left_max, nums2_left_max);
                }
                return (std::max(nums1_left_max, nums2_left_max) + std::min(nums1_right_min, nums2_right_min)) / 2.0;
            }
            else if (nums1_left_max > nums2_right_min) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }
        throw std::invalid_argument("The arrays are not sorted or input is invalid.");
    }
};
```