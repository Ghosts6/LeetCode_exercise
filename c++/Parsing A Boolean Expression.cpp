#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <stdexcept>

class Solution {
public:
    bool parseBoolExpr(const std::string& expression) {
        std::stack<char> operators;
        std::stack<std::vector<char>> operands;

        for (char ch : expression) {
            if (ch == 't' || ch == 'f') {
                operands.top().push_back(ch);
            } else if (ch == '!' || ch == '&' || ch == '|') {
                operators.push(ch);
                operands.push({});
            } else if (ch == ')') {
                char op = operators.top();
                operators.pop();
                std::vector<char> subExpr = operands.top();
                operands.pop();

                char result;
                if (op == '&') {
                    result = 't';
                    for (char c : subExpr) {
                        if (c == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                } else if (op == '|') {
                    result = 'f';
                    for (char c : subExpr) {
                        if (c == 't') {
                            result = 't';
                            break;
                        }
                    }
                } else { // '!'
                    result = (subExpr[0] == 't') ? 'f' : 't';
                }
                if (!operands.empty()) {
                    operands.top().push_back(result);
                } else {
                    operands.push({result});
                }
            }
        }
        return operands.top()[0] == 't';
    }
};

// Test cases
int main() {
    Solution solution;
    std::cout << std::boolalpha; 

    std::string expr1 = "&(|(f))";
    std::cout << "Test case 1: " << solution.parseBoolExpr(expr1) << std::endl; // Output: false

    std::string expr2 = "|(f,f,f,t)";
    std::cout << "Test case 2: " << solution.parseBoolExpr(expr2) << std::endl; // Output: true

    std::string expr3 = "!(&(f,t))";
    std::cout << "Test case 3: " << solution.parseBoolExpr(expr3) << std::endl; // Output: true

    return 0;
}
