# Count the Digits That Divide a Number 📊

## Problem Overview 🤔
The goal of this problem is to count how many digits in a given number can divide the number itself without leaving a remainder. 

For example:
- Number: `1012`
- Digits: `1`, `0`, `1`, `2`

In this case, `1`, `1`, and `2` divide `1012` evenly, but `0` cannot divide any number. So, the answer would be `3`. ✅

## Intuition 💡
To solve this problem, we can break it down into these steps:
1. Extract each digit from the number.
2. Check if the digit divides the number evenly (without a remainder).
3. Count the number of digits that divide the number.
4. Handle special cases like zero, because dividing by zero is not allowed. 🚫

## Approach 🛠️
1. **Save the original number**: We will need this to check if each digit divides the number evenly.
2. **Loop through each digit**: 
   - Use the modulo operation (`%`) to get the rightmost digit.
   - Remove the rightmost digit by dividing the number by 10.
   - If the digit divides the original number evenly, increase the count.
3. **Return the final count** of valid digits. 🎯

## Code
```cpp []
class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int originalNum = num;
        
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            
            // Avoid division by zero
            if (digit != 0 && originalNum % digit == 0) {
                count++;
            }
        }
        
        return count;
    }
};
```
```python3 []
class Solution:
    def countDigits(self, num: int) -> int:
        count = 0
        original_num = num
        
        while num > 0:
            digit = num % 10
            num //= 10
            
            # Avoid division by zero
            if digit != 0 and original_num % digit == 0:
                count += 1
        
        return count
```
```javascript []
var countDigits = function (num) {
    let count = 0;
    let originalNum = num;
    
    while (num > 0) {
        let digit = num % 10;
        num = Math.floor(num / 10);
        
        // Avoid division by zero
        if (digit !== 0 && originalNum % digit === 0) {
            count++;
        }
    }
    
    return count;
}
```