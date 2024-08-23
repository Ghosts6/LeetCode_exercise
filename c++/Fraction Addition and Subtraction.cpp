#include <iostream>
#include <string>
#include <numeric>
#include <cstdlib>

class Solution {
public:
    std::string fractionAddition(std::string expression) {
        int numerator = 0, denominator = 1, tempNumerator, tempDenominator;
        int n = expression.size();
        int i = 0;

        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                ++i;
            }
            
            tempNumerator = 0;
            while (i < n && isdigit(expression[i])) {
                tempNumerator = tempNumerator * 10 + (expression[i] - '0');
                ++i;
            }
            tempNumerator *= sign;

            ++i; 
            
            tempDenominator = 0;
            while (i < n && isdigit(expression[i])) {
                tempDenominator = tempDenominator * 10 + (expression[i] - '0');
                ++i;
            }

            numerator = numerator * tempDenominator + tempNumerator * denominator;
            denominator *= tempDenominator;

            int gcdValue = gcd(abs(numerator), denominator);
            numerator /= gcdValue;
            denominator /= gcdValue;
        }

        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
//  Test cases
int main() {
    Solution calculator;
    // Case 1
    std::string expression1 = "-1/2+1/2";
    std::cout << "Input: " << expression1 << "\nOutput: " << calculator.fractionAddition(expression1) << "\n\n";
    // Case 2
    std::string expression2 = "-1/2+1/2+1/3";
    std::cout << "Input: " << expression2 << "\nOutput: " << calculator.fractionAddition(expression2) << "\n\n";

    return 0;
}