#include <iostream>

class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            count += num & 1; 
            num >>= 1; 
        }
        return count;
    }

    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        return countSetBits(xorResult); 
    }
};
//  Test cases
int main() {
    Solution solution;

    // case 1
    int start1 = 10, goal1 = 7;
    std::cout << "Test case 1: " << solution.minBitFlips(start1, goal1) << std::endl; // Expected output: 3

    // case 2
    int start2 = 3, goal2 = 4;
    std::cout << "Test case 2: " << solution.minBitFlips(start2, goal2) << std::endl; // Expected output: 3

    // case 3
    int start3 = 0, goal3 = 15;
    std::cout << "Test case 3: " << solution.minBitFlips(start3, goal3) << std::endl; // Expected output: 4

    return 0;
}
