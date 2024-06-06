#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, std::__gcd(str1.size(), str2.size()));
    }
};
//  test case
int main() {
    Solution sol;

    std::string str1_1 = "ABCABC";
    std::string str2_1 = "ABC";
    std::string result1 = sol.gcdOfStrings(str1_1, str2_1);
    std::cout << "test Case : " << result1 << std::endl;

    return 0;
}
