# Intuition
🤔 My initial thought is to iterate through each base from 2 to n - 2 and check if the number n is palindromic in each base.

# Approach
💡 We can solve this problem by iterating through each base from 2 to n - 2 and converting the number n to that base. Then, we check if the representation of n in that base is palindromic.

# Complexity
- Time complexity:
🕒 The time complexity of our approach is \(O(n \log n)\), where \(n\) is the given number. This is because we iterate through each base from 2 to n - 2 and convert the number to that base.

- Space complexity:
🚀 The space complexity is \(O(\log n)\), as we store the representation of the number in each base.

# Answer
✨ just return false
### c++
```
return false;
```
### python
```
return false;
```
### java script
```
return false;
```

# Code
### c++
```cpp
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        if (n <= 2) return true;
        for (int base = 2; base < n - 1; ++base) {
            if (!isPalindromic(n, base)) return false;
        }
        return true;
    }
private:
    bool isPalindromic(int n, int base) {
        std::string numInBase = convertToBase(n, base);
        int left = 0, right = numInBase.size() - 1;
        while (left < right) {
            if (numInBase[left++] != numInBase[right--]) return false;
        }
        return true;
    }
    std::string convertToBase(int n, int base) {
        std::string result = "";
        while (n > 0) {
            result = std::to_string(n % base) + result;
            n /= base;
        }
        return result;
    }
};
```
### python
```python
class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        if n <= 2:
            return True
        for base in range(2, n - 1):
            if not self.isPalindromic(n, base):
                return False
        return True

    def isPalindromic(self, n: int, base: int) -> bool:
        num_in_base = self.convertToBase(n, base)
        left, right = 0, len(num_in_base) - 1
        while left < right:
            if num_in_base[left] != num_in_base[right]:
                return False
            left += 1
            right -= 1
        return True

    def convertToBase(self, n: int, base: int) -> str:
        result = ""
        while n > 0:
            result = str(n % base) + result
            n //= base
        return result
```
### java script
```javascript
class Solution {
    isStrictlyPalindromic(n) {
        if (n <= 2) return true;
        for (let base = 2; base < n - 1; ++base) {
            if (!this.isPalindromic(n, base)) return false;
        }
        return true;
    }

    isPalindromic(n, base) {
        const numInBase = this.convertToBase(n, base);
        let left = 0, right = numInBase.length - 1;
        while (left < right) {
            if (numInBase[left++] !== numInBase[right--]) return false;
        }
        return true;
    }

    convertToBase(n, base) {
        let result = "";
        while (n > 0) {
            result = String(n % base) + result;
            n = Math.floor(n / base);
        }
        return result;
    }
}
```