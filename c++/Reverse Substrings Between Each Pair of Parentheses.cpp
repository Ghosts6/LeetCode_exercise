#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(const std::string& s) {
        std::stack<char> st;
        
        for (char c : s) {
            if (c != ')') {
                st.push(c);
            } else {
                std::string temp;
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
              
                for (char t : temp) {
                    st.push(t);
                }
            }
        }
        std::string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
//  test case
int main() {
    Solution solution;

    std::string s = "(abcd)";
    std::string result = solution.reverseParentheses(s);
    
    std::cout << "Input: " << s << std::endl;
    std::cout << "Output: " << result << std::endl; 
    
    return 0;
}
