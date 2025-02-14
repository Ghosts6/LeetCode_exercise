#include <iostream>
#include <cstring>
#include <cctype>

class Solution {
    public:
    std::string clearDigits(const std::string& s) {
        std::string stack;
        for (char c : s) {
            if (isdigit(c)) {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }  
};

// Test cases 
int main() {
    Solution solution;
    // case 1
    std::string s1 = "abc";
    std::cout<<"result of test case 1:"<<solution.clearDigits(s1)<<std::endl; // Expected Output: "abc"
    // case 2
    std::string s2 = "cb34";
    std::cout<<"result of test case 2:"<<solution.clearDigits(s2)<<std::endl; // Expected Output: ""

    return 0;
}
