#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        int n = days.size();
        std::vector<int> dp(366, 0);
        std::vector<bool> travel(366, false);

        for (int day : days) {
            travel[day] = true;
        }
        
        for (int i = 1; i <= 365; ++i) {
            if (!travel[i]) {
                dp[i] = dp[i - 1]; 
                continue;
            }
            
            dp[i] = dp[i - 1] + costs[0];
            dp[i] = std::min(dp[i], dp[std::max(0, i - 7)] + costs[1]); 
            dp[i] = std::min(dp[i], dp[std::max(0, i - 30)] + costs[2]); 
        }
        
        return dp[365];
    }
};
// Test cases
int main() {
    Solution solution;

    // Test case 1
    std::vector<int> days1 = {1, 4, 6, 7, 8, 20};
    std::vector<int> costs1 = {2, 7, 15};
    std::cout << "Test Case 1 Output: " << solution.mincostTickets(days1, costs1) << std::endl; // Output: 11

    // Test case 2
    std::vector<int> days2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::vector<int> costs2 = {2, 7, 15};
    std::cout << "Test Case 2 Output: " << solution.mincostTickets(days2, costs2) << std::endl; // Output: 17

    return 0;
}