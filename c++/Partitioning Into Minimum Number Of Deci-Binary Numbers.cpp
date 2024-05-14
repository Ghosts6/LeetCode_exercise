#include <iostream>
#include <string>

class Solution {
public:
    int minPartitions(std::string n) {
        int maxDigit = 0;
        for (char digit : n) {
            maxDigit = std::max(maxDigit, digit - '0');
            if (maxDigit == 9) break;
        }
        return maxDigit;
    }
};
// test case
int main() {
    Solution solution;
    std::string n = "32";
    int result = solution.minPartitions(n);
    std::cout << "result of test case :" << result << std::endl;
    return 0;
}
