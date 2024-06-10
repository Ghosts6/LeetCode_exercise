#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        std::vector<int> expected = heights; 
        std::sort(expected.begin(), expected.end());
        
        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) {
                ++count;
            }
        }
        return count;
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<int> heights = {1, 1, 4, 2, 1, 3};
    int result = sol.heightChecker(heights);
    
    std::cout << "result of test case" << result << std::endl;


    return 0;
}
