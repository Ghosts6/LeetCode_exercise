# 📋 N-th Tribonacci Number

## 💡 Intuition
The Tribonacci sequence is a generalization of the Fibonacci sequence where each term is the sum of the three preceding ones, starting from 0, 1, and 1. The key observation is that the N-th Tribonacci number can be computed iteratively by maintaining only the last three computed values, which helps in optimizing both time and space complexity.

## 🛠️ Approach
1. **Base Cases**: 
    - If `n == 0`, return 0.
    - If `n == 1` or `n == 2`, return 1.
   
2. **Iterative Calculation**:
    - Start with the first three Tribonacci numbers: `T0 = 0`, `T1 = 1`, `T2 = 1`.
    - Use a loop to iterate from 3 to `n`. In each iteration, compute the next Tribonacci number as the sum of the last three values.
    - Update the three values to slide the window forward.

3. **Return the Result**:
    - After the loop, `T2` will contain the N-th Tribonacci number.

## 🧮 Complexity
- **Time complexity**: 
    - O(n): We calculate the Tribonacci number by iterating through a loop `n` times.
  
- **Space complexity**: 
    - O(1): Only a constant amount of space is used, irrespective of the input size, for storing the three necessary values (`T0`, `T1`, `T2`).


## 💻 Code
```python []
class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        t0, t1, t2 = 0, 1, 1
        for i in range(3, n + 1):
            tn = t0 + t1 + t2
            t0, t1, t2 = t1, t2, tn
        return t2

```
```C++ []
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        for (int i = 3; i <= n; ++i) {
            int tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }
        return t2;
    }
};
```