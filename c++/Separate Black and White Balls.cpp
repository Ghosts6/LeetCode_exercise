#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    long long minimumSteps(const std::string& s) {
        long long swaps = 0;
        int blackCount = 0;
        
        for (char ball : s) {
            if (ball == '0') {
                swaps += blackCount;
            } else {
                ++blackCount;
            }
        }
        
        return swaps;
    }
};

// Test cases
int main() {
    Solution solution;
    //  case 1
    std::string s1 = "101";
    std::cout << "Test case 1: Input: " << s1 << " Output: " << solution.minimumSteps(s1) << std::endl;
    //  case 2
    std::string s2 = "100";
    std::cout << "Test case 2: Input: " << s2 << " Output: " << solution.minimumSteps(s2) << std::endl;
    //  case 3
    std::string s3 = "0111";
    std::cout << "Test case 3: Input: " << s3 << " Output: " << solution.minimumSteps(s3) << std::endl;
    
    return 0;
}
