#include <iostream>
#include <vector>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int maxSize = 0;

        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    ++count;
                }
            }
            maxSize = std::max(maxSize, count);
        }
        
        return maxSize;
    }
};

// Test cases 
int main() {
    Solution solution;

    // case 1
    std::vector<int> candidates1 = {16, 17, 71, 62, 12, 24, 14};
    std::cout << "Test Case 1 Output: " << solution.largestCombination(candidates1) << std::endl; // Expected output: 4
    

    // case 2
    std::vector<int> candidates2 = {8, 8};
    std::cout << "Test Case 2 Output: " << solution.largestCombination(candidates2) << std::endl; // Expected output: 2
    
    return 0;
}
