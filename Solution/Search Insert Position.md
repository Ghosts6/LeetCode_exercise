# 📜 Search Insert Position

## 💡 Intuition
The goal is to find the position where a given target value should be inserted in a sorted list (nums). If the target is already present, return its index. If it's not present, return the index where it would be if inserted in order.

## 🛠️ Approach
1.  Binary Search: We initialize two pointers, left and right, which represent the range of the array we're searching within.
left starts at the beginning (0) and right starts at the end (len(nums) - 1).

2.  In each iteration:
Compute the middle index: mid = left + (right - left) // 2.
If nums[mid] == target, we've found the target, so return mid.
If nums[mid] < target, the target must be in the right half, so update left to mid + 1.
If nums[mid] > target, the target must be in the left half, so update right to mid - 1.

3.  If the target is not found after the loop, the correct insertion position is where left is pointing. This is because all elements before left are smaller than the target, and all elements after left are greater than the target.

## ⏰ Complexity
- Time complexity:O(log n)

- Space complexity:O(1)

## 💻 Code
```c++ []
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;  
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }  
        return left;
    }
};
```
```python3 []
class Solution:
    def searchInsert(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left
```