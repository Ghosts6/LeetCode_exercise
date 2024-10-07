#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int minLength(std::string s) {
        std::stack<char> st;
        for (char c : s) {
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop(); 
            } else {
                st.push(c);  
            }
        }
        return st.size();  
    }
};
//  Test cases
int main() {
    Solution reducer;
    //  case 1
    std::string test1 = "ABFCACDB";
    std::cout << "Test 1 - Input: " << test1 << "\n";
    std::cout << "Output: " << reducer.minLength(test1) << "\n";  // Expected Output: 2
    // case 2
    std::string test2 = "ACBBD";
    std::cout << "Test 2 - Input: " << test2 << "\n";
    std::cout << "Output: " << reducer.minLength(test2) << "\n";  // Expected Output: 5
    // case 3
    std::string test3 = "ABCD";
    std::cout << "Test 3 - Input: " << test3 << "\n";
    std::cout << "Output: " << reducer.minLength(test3) << "\n";  // Expected Output: 0
       
    return 0;
}
