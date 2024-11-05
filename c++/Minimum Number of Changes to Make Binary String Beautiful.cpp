#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int minChanges(std::string s) {
        int changes = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                ++changes;  
            }
        }
        
        return changes;
    }
};
// Test cases
int main() {
    Solution solution;

    // case 1
    std::string s1 = "1001";
    std::cout << "Test Case 1:" << std::endl;
    std::cout << "Input: " << s1 << std::endl;
    std::cout << "Output: " << solution.minChanges(s1) << std::endl;  // Expected output: 2

    // case 2
    std::string s2 = "10";
    std::cout << "Test Case 2:" << std::endl;
    std::cout << "Input: " << s2 << std::endl;
    std::cout << "Output: " << solution.minChanges(s2) << std::endl;  // Expected output: 1

    // case 3
    std::string s3 = "0000";
    std::cout << "Test Case 3:" << std::endl;
    std::cout << "Input: " << s3 << std::endl;
    std::cout << "Output: " << solution.minChanges(s3) << std::endl;  // Expected output: 0

    return 0;
}