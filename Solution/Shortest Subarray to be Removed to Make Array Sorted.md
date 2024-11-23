# 📜 Shortest Subarray to be Removed to Make Array Sorted

## 💡 Intuition
The problem revolves around finding the shortest subarray that can be removed to make the entire array sorted. To achieve this:
- First, we observe the portions of the array that are already sorted from the beginning and the end.
- Then, we attempt to "merge" these sorted sections efficiently while minimizing the length of the subarray to remove.  

By leveraging two-pointers and simple observations, we avoid exhaustive checking and optimize the solution.


## 🛠️ Approach
1. **Identify the sorted prefix:**  
   Traverse the array from the start and find the longest prefix where each element is ≤ the next one.

2. **Identify the sorted suffix:**  
   Traverse the array from the end and find the longest suffix where each element is ≤ the previous one.

3. **Merge the sorted sections:**  
   Use a two-pointer approach to attempt merging the prefix and suffix by ensuring that the values in the prefix are ≤ the values in the suffix.

4. **Minimize the length to remove:**  
   Compare three options:  
   - Removing the elements between the prefix and suffix directly.  
   - Removing elements beyond the prefix.  
   - Removing elements before the suffix.  


## ⏰ Complexity
- **Time Complexity:**  
  \(O(n)\) — Single pass for prefix, suffix, and the merging step.
  
- **Space Complexity:**  
  \(O(1)\) — We use only a few variables for indexing and tracking results.



# 💻 Code
```cpp []
class Solution {
public:
    int findLengthOfShortestSubarray(std::vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            ++left;
        }

        if (left == n - 1) {
            return 0;
        }

        while (right > 0 && arr[right - 1] <= arr[right]) {
            --right;
        }

        int result = std::min(n - left - 1, right); 

        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = std::min(result, j - i - 1);
                ++i;
            } else {
                ++j;
            }
        }

        return result;
    }
};
```
```python []
class Solution:
    def findLengthOfShortestSubarray(self, arr):
        n = len(arr)
        left = 0
        right = n - 1

        while left < n - 1 and arr[left] <= arr[left + 1]:
            left += 1

        if left == n - 1:
            return 0

        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1
        
        result = min(n - left - 1, right)

        i, j = 0, right
        while i <= left and j < n:
            if arr[i] <= arr[j]:
                result = min(result, j - i - 1)
                i += 1
            else:
                j += 1
        
        return result
```
```js []
var findLengthOfShortestSubarray = function (arr) {
    const n = arr.length;
    let left = 0;
    let right = n - 1;

    while (left < n - 1 && arr[left] <= arr[left + 1]) {
        left++;
    }

    if (left === n - 1) {
        return 0;
    }

    while (right > 0 && arr[right - 1] <= arr[right]) {
        right--;
    }

    let result = Math.min(n - left - 1, right);

    let i = 0, j = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            result = Math.min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }

    return result;
}
```