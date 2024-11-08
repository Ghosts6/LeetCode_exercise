#include <iostream>

class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= start + 2 * i;
        }
        return result;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    int n1 = 5;
    int start1 = 0;
    std::cout << "Output for n = " << n1 << ", start = " << start1 << ": "<< solution.xorOperation(n1, start1) << std::endl;

    // case 2
    int n2 = 4;
    int start2 = 3;
    std::cout << "Output for n = " << n2 << ", start = " << start2 << ": " << solution.xorOperation(n2, start2) << std::endl;

    return 0;
}