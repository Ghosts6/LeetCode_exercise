#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCount(std::vector<int> banned, int n, int maxSum) {
        std::sort(banned.begin(), banned.end());

        int totalSum = 0, count = 0;

        for (int i = 1; i <= n; ++i) {
            if (std::binary_search(banned.begin(), banned.end(), i)) {
                continue;
            }

            if (totalSum + i > maxSum) {
                break;
            }

            totalSum += i;
            ++count;
        }

        return count;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    std::vector<int> banned1 = {1, 5, 6};
    int n1 = 5;
    int maxSum1 = 6;
    std::cout << solution.maxCount(banned1, n1, maxSum1) << std::endl; // Output: 2

    // Test case 2
    std::vector<int> banned2 = {1, 2, 3, 4, 5, 6, 7};
    int n2 = 8;
    int maxSum2 = 1;
    std::cout << solution.maxCount(banned2, n2, maxSum2) << std::endl; // Output: 0

    // Test case 3 
    std::vector<int> banned3 = {11};
    int n3 = 7;
    int maxSum3 = 50;
    std::cout << solution.maxCount(banned3, n3, maxSum3) << std::endl; // Output: 7

    return 0;
}
