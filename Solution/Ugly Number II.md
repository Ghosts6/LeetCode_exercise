# 📜 Ugly Number II


## 💡 Intuition
Ugly numbers are numbers whose only prime factors are 2, 3, or 5. The sequence starts with 1, and each next ugly number is the smallest number that can be formed by multiplying 2, 3, or 5 with an earlier ugly number. The goal is to efficiently generate the n-th ugly number using this insight.

## 🛠️ Approach
1.  Initialization: Start by defining an array uglyNumbers where each element stores an ugly number. The first ugly number is always 1.
 
2.  Pointers: Use three pointers i2, i3, and i5 to track which index of the ugly number array should be multiplied by 2, 3, and 5, respectively, to generate the next multiple.

3.  Next Multiple Calculation: At each iteration, choose the smallest number from the candidates nextMultipleOf2, nextMultipleOf3, and nextMultipleOf5. This will be the next ugly number.

4.  Update Pointers: Depending on which multiple was chosen as the next ugly number, increment the corresponding pointer (i.e., i2, i3, or i5) and compute the next multiple.
 
5.  Continue this process until the array is filled with the first n ugly numbers. Return the n-th number in the list.

## ⏰ Complexity
- Time complexity:
O(n), because we iterate through the list of ugly numbers and calculate each ugly number once.

- Space complexity:
O(n), because we need an array to store the first n ugly numbers.

## 💻 Code
```c []
int nthUglyNumber(int n) {
    int uglyNumbers[n];
    uglyNumbers[0] = 1;  

    int i2 = 0, i3 = 0, i5 = 0;  
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;
    int nextUglyNumber;

    for (int i = 1; i < n; i++) {
        nextUglyNumber = nextMultipleOf2 < nextMultipleOf3 ? (nextMultipleOf2 < nextMultipleOf5 ? nextMultipleOf2 : nextMultipleOf5) : (nextMultipleOf3 < nextMultipleOf5 ? nextMultipleOf3 : nextMultipleOf5);
        uglyNumbers[i] = nextUglyNumber;

        if (nextUglyNumber == nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }
    return uglyNumbers[n - 1];  
}
```
```c++ []
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;

        int uglyNumbers[n];
        uglyNumbers[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;
        int nextUglyNumber;

        for (int i = 1; i < n; i++) {
            nextUglyNumber = std::min(nextMultipleOf2, std::min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;

            if (nextUglyNumber == nextMultipleOf2) {
                i2++;
                nextMultipleOf2 = uglyNumbers[i2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3) {
                i3++;
                nextMultipleOf3 = uglyNumbers[i3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5) {
                i5++;
                nextMultipleOf5 = uglyNumbers[i5] * 5;
            }
        }

        return uglyNumbers[n - 1];
    }
};

```
```python []
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n == 1:
            return 1

        uglyNumbers = [0] * n
        uglyNumbers[0] = 1

        i2 = i3 = i5 = 0
        nextMultipleOf2 = 2
        nextMultipleOf3 = 3
        nextMultipleOf5 = 5

        for i in range(1, n):
            nextUglyNumber = min(nextMultipleOf2, nextMultipleOf3, nextMultipleOf5)
            uglyNumbers[i] = nextUglyNumber

            if nextUglyNumber == nextMultipleOf2:
                i2 += 1
                nextMultipleOf2 = uglyNumbers[i2] * 2

            if nextUglyNumber == nextMultipleOf3:
                i3 += 1
                nextMultipleOf3 = uglyNumbers[i3] * 3

            if nextUglyNumber == nextMultipleOf5:
                i5 += 1
                nextMultipleOf5 = uglyNumbers[i5] * 5

        return uglyNumbers[n - 1]
```