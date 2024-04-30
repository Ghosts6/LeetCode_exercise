#include <iostream>
#include <string>

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
//  test case
int main() {
    Solution sol;
    std::string s1 = "abcde";
    std::cout << "result : \"" << s1 << "\": " << sol.scoreOfString(s1) << std::endl;
    return 0;
}
