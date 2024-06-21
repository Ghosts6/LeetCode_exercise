#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int totalSatisfied = 0;
        int maxAdditionalSatisfied = 0;
        int currentAdditionalSatisfied = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            if (!grumpy[i]) {
                totalSatisfied += customers[i];
            } else {
                currentAdditionalSatisfied += customers[i];
            }

            if (i >= minutes) {
                currentAdditionalSatisfied -= grumpy[i - minutes] * customers[i - minutes];
            }

            maxAdditionalSatisfied = std::max(maxAdditionalSatisfied, currentAdditionalSatisfied);
        }
        
        return totalSatisfied + maxAdditionalSatisfied;
    }
};

// test case
int main() {
    Solution solution;

    std::vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    std::vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    int result = solution.maxSatisfied(customers, grumpy, minutes);

    std::cout << "result: " << result << std::endl; 

    return 0;
}