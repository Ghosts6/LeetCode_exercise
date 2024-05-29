#include <iostream>
#include <string>

class Solution {
public:
    int numSteps(std::string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    --i;
                }
                if (i < 0) {
                    s = '1' + s;
                } else {
                    s[i] = '1';
                }
            }
            ++steps;
        }
        return steps;
    }
};
//  test case
int main() {
    Solution solution;
    std::string s = "1101";
    int result = solution.numSteps(s);
    std::cout << "result of test case: " << result << " (Expected: 6)" <<std::endl;

    return 0;
}
