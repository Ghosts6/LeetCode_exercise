# 📜 Find the Maximum Achievable Number

## 💡 Approach && Intuition
Problem Breakdown:
Operation Explanation: You can either increase or decrease a number by 1 while simultaneously increasing or decreasing the original num by 1.
Goal: After applying the operation at most t times, you need to find the maximum achievable number.

Step-by-Step Approach:
1.  Understanding the Operation:
Each operation allows you to move the number closer or farther from num.
Since you can perform this operation t times, the maximum effect you can have on num is increasing it by 2 * t (since each operation can increase or decrease the difference by 2).
2.  Formula:
The maximum achievable number is num + 2 * t. This is derived from the fact that in the best-case scenario, every operation increases the target number and simultaneously increases num.
3.  Return the Result:
The result is simply num + 2 * t.

## ⏰ Complexity
- Time complexity: O(1)


- Space complexity: O(1)


## 💻 Code
```cpp []
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int maxAchievable = num + 2 * t;
        return maxAchievable;
    }
};
```
```c []
int theMaximumAchievableX(int num, int t) {
    int maxAchievable = num + 2 * t;
    return maxAchievable;
}
```
```python []
class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        maxAchievable = num + 2 * t
        return maxAchievable
```
```js []
function theMaximumAchievableX(num, t) {
    const maxAchievable = num + 2 * t;
    return maxAchievable;
}
```