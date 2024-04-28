#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        digits[n - 1]++;
        for (int i = n - 1; i > 0; i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1]++;
            } else {
                break;
            }
        }
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
// test case
int main() {
    Solution sol;
    std::vector<int> digits = {9, 9, 9};
    std::vector<int> result = sol.plusOne(digits);
    std::cout << "result:";
    for (int digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;
    return 0;
}
