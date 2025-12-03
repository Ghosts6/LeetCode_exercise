#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdint>
#include <climits>
#include <iostream>

class Solution {
public:
    long long countTrapezoids(std::vector<std::vector<int>>& points) {
        const long long MOD = 1000000007;
        
        std::unordered_map<int, int64_t> y_counts;
        for (const auto& p : points) {
            y_counts[p[1]]++;
        }
        
        long long sum = 0;
        long long square_sum = 0;
        
        for (const auto& kv : y_counts) {
            long long count = kv.second;
            if (count >= 2) {
                long long comb2 = (count % MOD) * ((count - 1) % MOD) / 2 % MOD;
                sum = (sum + comb2) % MOD;
                square_sum = (square_sum + comb2 * comb2 % MOD) % MOD;
            }
        }

        long long sum_sq = (sum * sum) % MOD;
        long long numerator = (sum_sq - square_sum + MOD) % MOD;
        long long result = numerator * 500000004 % MOD;
        return result;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<std::vector<int>> points1 = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    long long result1 = sol.countTrapezoids(points1);
    std::cout << "result of test case 1 : " << result1 << std::endl; // Expected Output: 3

    // case 2
    std::vector<std::vector<int>> points2 = {{0,0},{1,0},{0,1},{2,1}};
    long long result2 = sol.countTrapezoids(points2);
    std::cout << "result of test case 2 : " << result2 << std::endl; // Expected Output: 1

    return 0;
}
