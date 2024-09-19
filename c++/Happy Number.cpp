#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getSumOfSquares(n); 
        }

        return n == 1;
    }

private:
    int getSumOfSquares(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};
//  test case
int main() {
    Solution solution;
    int n = 19; 
    
    if (solution.isHappy(n)) {
        std::cout << n << " is a happy number." << std::endl;
    } else {
        std::cout << n << " is not a happy number." << std::endl;
    }
    
    return 0;
}

