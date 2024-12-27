#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxScoreSightseeingPair(std::vector<int>& values) {
        int maxScore = 0;
        int bestValue = values[0];
        
        for (int j = 1; j < values.size(); ++j) {
            maxScore = std::max(maxScore, bestValue + values[j] - j);
            bestValue = std::max(bestValue, values[j] + j);
        }
        
        return maxScore;
    }
};
// Test cases
int main() {
    Solution solution;  
    // Case 1
    std::vector<int> values1 = {8, 1, 5, 2, 6};
    std::cout << "Test Case 1: " << solution.maxScoreSightseeingPair(values1) << std::endl;
    // Case 2
    std::vector<int> values2 = {1, 2};
    std::cout << "Test Case 2: " << solution.maxScoreSightseeingPair(values2) << std::endl;
    
    return 0;
}