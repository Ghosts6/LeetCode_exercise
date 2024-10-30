# 🎯 ASCII Score Calculator

## 🧠 Problem Description
You are given a string `s`. The **score** of the string is defined as the sum of the absolute differences between the ASCII values of adjacent characters. Your task is to calculate and return this score.

## 💡 Intuition
To compute the score, we need to measure how much each character in the string differs from the one immediately before it. We can achieve this by summing the absolute differences between each consecutive character’s ASCII values.

## 🚀 Approach
1. **Initialize a score** variable to keep track of the accumulated differences.
2. **Iterate through the string**, starting from the second character.
3. For each character, calculate the **absolute difference** with the previous character and add it to the score.
4. Return the final score once all characters are processed.

## ⏳ Complexity Analysis
- **Time Complexity**: \(O(n)\), where \(n\) is the length of the string, since we visit each character once.
- **Space Complexity**: \(O(1)\), as we only use a fixed amount of space for storing the score.

## 🔧 Code
```cpp []
class Solution {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        for (int i = 1; i < s.size(); ++i) {
            score += abs(s[i] - s[i - 1]);
        }
        return score;
    }
};
```
```c []
int scoreOfString(char* s) {
    int score = 0;
    for (int i = 1; s[i] != '\0'; ++i) {
        score += abs(s[i] - s[i - 1]);
    }
    return score;
}
```
```python3 []
class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0
        for i in range(1, len(s)):
            score += abs(ord(s[i]) - ord(s[i - 1]))
        return score
```