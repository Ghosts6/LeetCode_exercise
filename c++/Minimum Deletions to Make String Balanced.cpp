#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int minimumDeletions(std::string s) {
        int totalA = 0, countA = 0, countB = 0, minDeletions = s.size();

        for (char c : s) {
            if (c == 'a') totalA++;
        }

        for (char c : s) {
            if (c == 'a') {
                countA++;
            } else {
                countB++;
            }

            int deletions = countB + (totalA - countA);
            minDeletions = std::min(minDeletions, deletions);
        }
        minDeletions = std::min(minDeletions, countB);
        minDeletions = std::min(minDeletions, totalA);
        
        return minDeletions;
    }
};
//  test case
int main() {
    Solution solution;
    
    std::string test1 = "aababbab";
    std::cout << "result of Test 1: " << solution.minimumDeletions(test1) << std::endl;

    std::string test2 = "bbaaaaabb";
    std::cout << "result of Test 2:" << solution.minimumDeletions(test2) << std::endl;
    
    return 0;
}