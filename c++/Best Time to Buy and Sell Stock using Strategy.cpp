#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxProfit(std::vector<int>& prices, std::vector<int>& strategy, int k) {
        int n = prices.size();
        long long baseProfit = 0;
        for (int i = 0; i < n; ++i) {
            baseProfit += (long long)strategy[i] * prices[i];
        }

        long long currentGain = 0;
        int halfK = k / 2;

        // Calculate gain for the first window [0, k-1]
        for (int i = 0; i < k; ++i) {
            int targetAction = (i < halfK) ? 0 : 1;
            currentGain += (long long)(targetAction - strategy[i]) * prices[i];
        }

        long long maxGain = std::max(0LL, currentGain);

        // Sliding window
        for (int i = 1; i <= n - k; ++i) {
            // Remove the element that is sliding out (index i-1)
            int oldTargetLeft = 0; 
            currentGain -= (long long)(oldTargetLeft - strategy[i - 1]) * prices[i - 1];

            // The element at i + halfK - 1 shifts from the "sell" zone to the "hold" zone
            // New Hold: i to i + halfK - 1
            // New Sell: i + halfK to i + k - 1
            int midIdx = i + halfK - 1;
            // Previously it was 'sell' (1), now it is 'hold' (0)
            currentGain -= (long long)(1 - strategy[midIdx]) * prices[midIdx]; // remove old sell contribution
            currentGain += (long long)(0 - strategy[midIdx]) * prices[midIdx]; // add new hold contribution

            // Add the new element sliding in (index i + k - 1) as a 'sell' (1)
            int newIdx = i + k - 1;
            currentGain += (long long)(1 - strategy[newIdx]) * prices[newIdx];

            maxGain = std::max(maxGain, currentGain);
        }

        return baseProfit + maxGain;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> prices1 = {4, 2, 8}; 
    std::vector<int> strategy1 = {-1, 0, 1};
    int k1 = 2;
        
    std::cout << "Result of test case 1 : " << sol.maxProfit(prices1, strategy1, k1) << std::endl; // Expected: 10

    // case 2
    std::vector<int> prices2 = {5, 4, 3};
    std::vector<int> strategy2 = {1, 1, 0};
    int k2 = 2;
   
    std::cout << "Result of test case 2 : " << sol.maxProfit(prices2, strategy2, k2) << std::endl; // Expected: 9

    return 0;
}
