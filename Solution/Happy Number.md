# 📜 Happy Number

## 💡 Intuition
The problem is to determine whether a given number n is a happy number. A happy number is defined as a number that eventually reaches 1 when replaced by the sum of the square of each digit. If the sequence loops and never reaches 1, then the number is not a happy number.

## 🛠️ Approach
1.  Sum of Squares Function: Create a helper function to calculate the sum of squares of the digits of a number.
2.  Cycle Detection: Use a Set to keep track of the numbers we have already seen. If we encounter the same number again, it means we are in a cycle and will never reach 1.
3.  Main Loop: Keep calculating the sum of squares until either we get 1 (happy number) or encounter a repeated number (not a happy number).

## ⏰ Complexity
- Time complexity:O(log n). Each digit in the number is squared, and the number of digits is proportional to log(n).

- Space complexity:O(log n). In the worst case, the set can store all numbers formed by sum of squares until a cycle is detected or 1 is reached.

## 💻 Code
```javascript []
var isHappy = function(n) {
    const seen = new Set();
    
    const getSumOfSquares = (num) => {
        let sum = 0;
        while (num > 0) {
            const digit = num % 10;
            sum += digit * digit;
            num = Math.floor(num / 10);
        }
        return sum;
    };
    
    while (n !== 1 && !seen.has(n)) {
        seen.add(n);
        n = getSumOfSquares(n);
    }
    
    return n === 1;
};
```
```python []
class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        
        def getSumOfSquares(num):
            total_sum = 0
            while num > 0:
                digit = num % 10
                total_sum += digit * digit
                num //= 10
            return total_sum

        while n != 1 and n not in seen:
            seen.add(n)
            n = getSumOfSquares(n)
        
        return n == 1
```
```c++ []
class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getSumOfSquares(n); 
        }

        return n == 1;
    }

private:
    int getSumOfSquares(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};
```
```c []
inline int getSumOfSquares(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getSumOfSquares(n);

    while (fast != 1 && slow != fast) {
        slow = getSumOfSquares(slow);
        fast = getSumOfSquares(getSumOfSquares(fast));
    }

    return fast == 1;
}
```