# 📜 Score of a String

# 💡 Intuition
The score of a string can be calculated by summing the absolute differences between the ASCII values of consecutive characters.

# 🛠️ Approach
Iterate through the string from the second character to the end, and accumulate the absolute difference between the current character and the previous character.

# ⏰ Complexity
- Time complexity:
O(n), where n is the length of the string. Each character is visited once.

- Space complexity:
O(1), as we are only using a fixed amount of space for the score and the loop variable.

# 💻 Code
### C++
```cpp
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
### C
```c
int scoreOfString(char* s) {
    int score = 0;
    for (int i = 1; s[i] != '\0'; ++i) {
        score += abs(s[i] - s[i - 1]);
    }
    return score;
}
```
### python
```py
class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0
        for i in range(1, len(s)):
            score += abs(ord(s[i]) - ord(s[i - 1]))
        return score
```