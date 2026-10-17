#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
	if (n <= 0) return false;

	while(n % 3 == 0) {
	    n /= 3;
	}

	return n == 1;
    }
};

// Test cases
int main() {
    Solution sol;
    // case 1
    int n1 = 27;
    std::cout << "Result of test case 1: " << sol.isPowerOfThree(n1) << std::endl;

    // case 2
    int n2 = 0;
    std::cout << "Result of test case 2: " << sol.isPowerOfThree(n2) << std::endl;
    
    // case 3
    int n3 = -1;
    std::cout << "Result of test case 3: " << sol.isPowerOfThree(n3) << std::endl;
    
    return 0;
}
