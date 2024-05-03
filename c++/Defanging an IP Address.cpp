#include <iostream>
#include <string>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string defangedIP;
        for (char c : address) {
            if (c == '.') {
                defangedIP += "[.]";
            } else {
                defangedIP += c;
            }
        }
        return defangedIP;
    }
};
// test case
int main() {
    Solution sol;
    std::string ip = "1.1.1.1";
    std::string defangedIP = sol.defangIPaddr(ip);
    std::cout << "result of test case: " << defangedIP << std::endl;
    return 0;
}