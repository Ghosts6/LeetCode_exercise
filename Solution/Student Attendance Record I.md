# 📜 Student Attendance Record I


# 💡 Intuition
The function checks whether a given string represents attendance records of a student. The function returns True if the student is eligible for the award and False otherwise.

#  🛠️ Approach
1.  Initialize absence count and late streak to 0.
2.  Iterate through the string, updating counts for absences and late streaks accordingly.
3.  If the counts exceed the thresholds, return False. Otherwise, return True.

# ⏰ Complexity
- Time complexity:
all the solutions have a time complexity of O(n), where n is the length of the input string s.

- Space complexity:
all the  solutions have a space complexity of O(1) as they use only a constant amount of extra space regardless of the size of the input string.

# Code
### c++
```cpp
class Solution {
public:
    bool checkRecord(const std::string& s) {
        int absences = 0;
        int lateStreak = 0;

        for (char c : s) {
            if (c == 'A') {
                absences++;
                if (absences >= 2) {
                    return false;
                }
                lateStreak = 0;
            } else if (c == 'L') {
                lateStreak++;
                if (lateStreak >= 3) {
                    return false;
                }
            } else {
                lateStreak = 0;
            }
        }
        
        return true;
    }
};
```
### c
```c
bool checkRecord(char* s) {
    int absences = 0;
    int lateStreak = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            absences++;
            if (absences >= 2) {
                return false;
            }
            lateStreak = 0;
        } else if (s[i] == 'L') {
            lateStreak++;
            if (lateStreak >= 3) {
                return false;
            }
        } else {
            lateStreak = 0;
        }
    }
    
    return true;
}
```
### python
```py
class Solution:
    def checkRecord(self, s: str) -> bool:
        absences = 0
        late_streak = 0

        for c in s:
            if c == 'A':
                absences += 1
                if absences >= 2:
                    return False
                late_streak = 0
            elif c == 'L':
                late_streak += 1
                if late_streak >= 3:
                    return False
            else:
                late_streak = 0
        
        return True
```