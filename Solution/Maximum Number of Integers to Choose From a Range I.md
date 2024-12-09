# 📜 Maximum Number of Integers to Choose From a Range I

## 💡 Intuition
The problem involves selecting the maximum number of integers from a range `[1, n]` such that their sum does not exceed a given `maxSum` and none of the selected integers belong to a `banned` list. The approach combines sorting, binary search, and a greedy strategy to efficiently make selections.

## 🛠️ Approach
1. **Sort the Banned List**: Sorting allows efficient checks using binary search to determine if an integer is in the banned list.
2. **Iterate Over Range**: Loop through the range `[1, n]`:
   - Skip numbers present in the banned list.
   - If adding the current number exceeds `maxSum`, stop further processing.
   - Otherwise, add the number to the total sum and increase the count.
3. **Binary Search for Banned Check**: Use binary search to quickly check if an integer is in the banned list.

This approach ensures we process numbers in ascending order and stop as soon as the `maxSum` constraint is violated.

## ⏰ Complexity
- **Time Complexity**:
  - Sorting the `banned` list: \(O(k \log k)\), where \(k\) is the length of the `banned` list.
  - Iterating through the range: \(O(n)\).
  - Binary search for each integer: \(O(\log k)\).
  - Overall: \(O(k \log k + n \log k)\).
- **Space Complexity**:
  - Storage for the sorted `banned` list: \(O(k)\).
  - Total: \(O(k)\).

## 💻 Code
```cpp []
class Solution {
public:
    int maxCount(std::vector<int> banned, int n, int maxSum) {
        std::sort(banned.begin(), banned.end());

        int totalSum = 0, count = 0;

        for (int i = 1; i <= n; ++i) {
            if (std::binary_search(banned.begin(), banned.end(), i)) {
                continue;
            }

            if (totalSum + i > maxSum) {
                break;
            }

            totalSum += i;
            ++count;
        }

        return count;
    }
};
```
```python3 []
class Solution:
    def maxCount(self, banned, n, maxSum):
        banned.sort()
        total_sum = 0
        count = 0

        for i in range(1, n + 1):
            if self.is_banned(banned, i):
                continue
            
            if total_sum + i > maxSum:
                break
            
            total_sum += i
            count += 1
        
        return count
    
    def is_banned(self, banned, x):
        index = bisect_left(banned, x)
        return index < len(banned) and banned[index] == x
```
```javascript []
var maxCount = function(banned, n, maxSum) {
    banned.sort((a, b) => a - b);

    let sum = 0, count = 0;

    for (let i = 1; i <= n; i++) {
        if (isBanned(banned, i)) continue;

        if (sum + i > maxSum) break;

        sum += i;
        count++;
    }

    return count;
};

function isBanned(banned, x) {
    let left = 0, right = banned.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (banned[mid] === x) return true;
        if (banned[mid] < x) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}
```