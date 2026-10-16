#include <iostream>

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3) return true;
        return n % 4 != 0; 
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    int n1 = 4;
    std::cout << "Result of test case 1 : " << sol.canWinNim(n1) << std::endl;

    // case 2
    int n2 = 1;
    std::cout << "Result of test case 2 : " << sol.canWinNim(n2) << std::endl;

    // case 3
    int n3 = 2;
    std::cout << "Result of test case 3 : " << sol.canWinNim(n3) << std::endl;

    // edge
    int e1 = 5;
    std::cout << "Result for 5: " << sol.canWinNim(e1) << std::endl;

    return 0;
}
