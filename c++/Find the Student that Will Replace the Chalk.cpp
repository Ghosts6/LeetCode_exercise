#include <iostream>
#include <vector>

class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        long long totalChalk = 0;
        for (int amount : chalk) {
            totalChalk += amount;
        }

        k %= totalChalk;

        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};
//  Test cases
int main() {
    Solution solution;

    // case 1
    std::vector<int> chalk1 = {5, 1, 5};
    int k1 = 22;
    std::cout << "Output: " << solution.chalkReplacer(chalk1, k1) << std::endl; // Expected Output: 0

    // case 2
    std::vector<int> chalk2 = {3, 4, 1, 2};
    int k2 = 25;
    std::cout << "Output: " << solution.chalkReplacer(chalk2, k2) << std::endl; // Expected Output: 1

    return 0;
}
