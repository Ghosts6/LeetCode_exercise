#include<iostream>

class Solution {
    public:
        long long coloredCells(int n) {
            return 1LL + 2LL * n * (n - 1); // Counting the number of colored cells with formula 1 + 2 * n * (n - 1)
        }
};

// test cases
int main(){
    Solution solution;
    // case 1
    int n_1 = 1;
    std::cout << "Result of test case 1 : " << solution.coloredCells(n_1) << std::endl; // Expected output: 1

    // case 2
    int n_2 = 2;
    std::cout << "Result of test case 2 : " << solution.coloredCells(n_2) << std::endl; // Expected output: 5

    return 0;
}