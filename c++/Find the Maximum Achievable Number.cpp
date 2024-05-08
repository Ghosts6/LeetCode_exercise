#include <iostream>
#include <cmath>

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int maxAchievable = num + 2 * t;
        return maxAchievable;
    }
};
// test class
int main() {
    Solution sol;
    int num = 10, t = 3;
    int maxAchievable = sol.theMaximumAchievableX(num, t);
    std::cout << "maximum achievable number: " << maxAchievable << std::endl;
    return 0;
}