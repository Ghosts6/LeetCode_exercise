#include <iostream>
#include <string>

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
//  test case
int main() {
    Solution solution;

    std::string test1 = "PPALLP";
    std::string test2 = "PPALLL";
    std::string test3 = "PAALP";

    std::cout << std::boolalpha;
    std::cout << "Test 1: " << solution.checkRecord(test1) << " (expected: true)" << std::endl;
    std::cout << "Test 2: " << solution.checkRecord(test2) << " (expected: false)" << std::endl;
    std::cout << "Test 3: " << solution.checkRecord(test3) << " (expected: false)" << std::endl;

    return 0;
}
