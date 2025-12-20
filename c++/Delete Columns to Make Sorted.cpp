#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {
        int deleteCount = 0;
        int rows = strs.size();
        int cols = strs[0].length();

        for (int c = 0; c < cols; ++c) {
            for (int r = 1; r < rows; ++r) {
                // If column is not lexicographically sorted
                if (strs[r][c] < strs[r - 1][c]) {
                    deleteCount++;
                    break; 
                }
            }
        }
        return deleteCount;
    }
};

int main() {
    Solution sol;

    // case 1
    std::vector<std::string> strs1 = {"cba", "daf", "ghi"}; 
    std::cout << "Result of test case 1 : " << sol.minDeletionSize(strs1) << std::endl; 

    // case 2
    std::vector<std::string> strs2 = {"a", "b"};
    std::cout << "Result of test case 2 : " << sol.minDeletionSize(strs2) << std::endl; 

    // case 3
    std::vector<std::string> strs3 = {"zyx", "wvu", "tsr"};
    std::cout << "Result of test case 3 : " << sol.minDeletionSize(strs3) << std::endl; 

    return 0;
}
