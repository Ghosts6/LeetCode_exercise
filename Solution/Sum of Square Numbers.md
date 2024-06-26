# 📜 Sum of Square Numbers

# 💡 Intuition
The problem is to determine if a given number c can be expressed as the sum of squares of two integers. The key insight is to use a two-pointer approach where one pointer starts at 0 and the other starts at the largest possible integer whose square is less than or equal to c. By adjusting these pointers, we can efficiently check all possible pairs of integers.

# 🛠️ Approach
1.  Initialization:
Initialize two pointers: left starts at 0 and right starts at the integer part of the square root of c.

2.  Two-pointer Technique:
Calculate the sum of squares of the numbers at these pointers.
If the sum equals c, return true.If the sum is less than 
c, increment the left pointer to increase the sum.
If the sum is greater than c, decrement the right pointer to decrease the sum.Repeat until the pointers meet.

3.  Termination:
If no such pair is found, return false.
# ⏰ Complexity
- Time complexity:

The time complexity is O(√c) because in the worst case, each pointer will move from one end to the other, which involves iterating up to the square root of c.

- Space complexity:
The space complexity is O(1) because we only use a few extra variables to store the pointers and the sum, and no additional data structures are required.

# 💻 Code
```c []
bool judgeSquareSum(int c) {
    if (c < 0) return false;
    
    long long left = 0;
    long long right = (long long)sqrt(c);
    
    while (left <= right) {
        long long sum = left * left + right * right;
        if (sum == c) {
            return true;
        } else if (sum < c) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}
```
```c++ []
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false;
        
        long long left = 0;
        long long right = (long long)sqrt(c);
        
        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};
```
```python []
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c < 0:
            return False
        
        left = 0
        right = int(math.sqrt(c))
        
        while left <= right:
            sum = left * left + right * right
            if sum == c:
                return True
            elif sum < c:
                left += 1
            else:
                right -= 1
                
        return False
```
