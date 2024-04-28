#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string result = "";
        for (char digit : num) {
            while (k > 0 && !result.empty() && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        result.resize(result.size() - k);
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        
        return (i == result.size()) ? "0" : result.substr(i);
    }
};
// test case
int main() {
    Solution sol;
    std::string num = "1432219";
    int k = 3;
    std::string result = sol.removeKdigits(num, k);
    std::cout << "result:" << result << std::endl;
    return 0;
}
