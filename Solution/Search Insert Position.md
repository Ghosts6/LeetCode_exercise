# 📜 Search Insert Position

## 💡 Intuition
The objective is to determine the index where a given target should be inserted in a sorted array (`nums`) to maintain the order. If the target exists in the array, return its index; otherwise, return the index where it should be placed.

## 🛠️ Approach
1. **Binary Search**:
   - We initialize two pointers, `left` and `right`, representing the search bounds within the array.
   - Set `left` to 0 (start of the array) and `right` to `nums.length - 1` (end of the array).

2. **Iterative Search**:
   - While `left` is less than or equal to `right`, calculate the `mid` index as `left + (right - left) // 2`.
   - Check the following conditions:
     - If `nums[mid]` equals the target, return `mid` since the target exists in the array.
     - If `nums[mid]` is less than the target, shift the `left` pointer to `mid + 1` to search in the right half.
     - If `nums[mid]` is greater than the target, shift the `right` pointer to `mid - 1` to search in the left half.

3. **Insertion Point**:
   - If the target is not found in the array, return `left`, which represents the position where the target should be inserted.

## ⏰ Complexity
- **Time Complexity**: `O(log n)` - Binary search reduces the search space by half each time.
- **Space Complexity**: `O(1)` - We are not using any extra space beyond the input.

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
```js []
var searchInsert = function(nums, target) {
    let left = 0, right = nums.length - 1;
    while (left <= right) {
        let mid = left + Math.floor((right - left) / 2);
        if (nums[mid] === target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
};
```