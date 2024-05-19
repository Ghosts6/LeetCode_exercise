#include <iostream>

class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                matches += n / 2;
                n /= 2;
            } else {
                matches += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        return matches;
    }
};
//  test case
int main() {
    Solution solution;
    int n1 = 7;
    std::cout << "number of matches for " << n1 << " teams: " << solution.numberOfMatches(n1) << std::endl;

    return 0;
}