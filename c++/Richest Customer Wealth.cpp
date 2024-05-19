#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumWealth(const std::vector<std::vector<int>>& accounts) {
        int maxWealth = 0;
        for (const auto& customer : accounts) {
            int currentWealth = std::accumulate(customer.begin(), customer.end(), 0);
            maxWealth = std::max(maxWealth, currentWealth);
        }
        return maxWealth;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> accounts1 = {{1,2,3}, {3,2,1}};
    
    std::cout << "result of test case " << solution.maximumWealth(accounts1) << std::endl;

    return 0;
}