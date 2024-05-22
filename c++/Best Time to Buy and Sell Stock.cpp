#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = std::max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << "result of test case {7, 1, 5, 3, 6, 4} : " << solution.maxProfit(prices) << std::endl;
    return 0;
}
