# Intuition
The problem asks us to determine if a given number 
𝑛
n is an "ugly number." An ugly number is defined as a positive integer whose prime factors are limited to 2, 3, and 5. Therefore, any number that can be divided by 2, 3, or 5 until it reduces to 1 is considered ugly. If any prime factor other than 2, 3, or 5 is found in the number, it cannot be considered ugly.

# Code
```C []
bool isUgly(int n) {
    if (n <= 0) return false; 

    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;

    return n == 1;
}
```
```C++ []
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        return n == 1;
    }
};
```
```Python []
class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0:
            return False

        for factor in [2, 3, 5]:
            while n % factor == 0:
                n //= factor

        return n == 1
```
```Js []
var isUgly = function(n) {
    if (n <= 0) return false;

    while (n % 2 === 0) n /= 2;
    while (n % 3 === 0) n /= 3;
    while (n % 5 === 0) n /= 5;

    return n === 1;
};
```