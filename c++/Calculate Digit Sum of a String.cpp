#include <iostream>
#include <string>

class Solution {
public:
    std::string digitSum(std::string s, int k) {

        while (s.length() > k) {
            std::string result = "";

            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;

                for (int j = i; j < i + k && j < s.length(); j++) {
                    sum += s[j] - '0';
                }

                result += std::to_string(sum);
            }

            s = result;
        }

        return s;
    }
};

// Test case
int main() {
    Solution sol;

    // case 1
    std::string s1 = "11111222223";
    int k1 = 3;
    std::cout << "Result of test case 1 : " << sol.digitSum(s1, k1) << std::endl; // Expected: 135

    // case 2
    std::string s2 = "00000000";
    int k2 = 3;
    std::cout << "Result of test case 2 : " << sol.digitSum(s2, k2) << std::endl; // Expected: 000

    return 0;
}
