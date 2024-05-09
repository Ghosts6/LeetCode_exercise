#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end(), std::greater<int>());
        long long sum = 0;
        int n = std::min(k, static_cast<int>(happiness.size()));
        int decrementCount = 0;
        for (int i = 0; i < n; ++i) {
            if (happiness[i] <= decrementCount) break;
            sum += static_cast<long long>(happiness[i] - decrementCount); 
            decrementCount++; 
        }
        return sum;
    }
};

// test case
int main() {
    Solution sol;
    std::vector<int> happiness = {1, 2, 3};
    int k = 2;
    int result = sol.maximumHappinessSum(happiness, k);
    std::cout << "result of test case: " << result << std::endl;
    return 0;
}
