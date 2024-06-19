#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canMakeBouquets(const std::vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0;
        int flowers = 0;

        for (int day : bloomDay) {
            if (day <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }

            if (bouquets >= m) {
                return true;
            }
        }

        return false;
    }

    int minDays(std::vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (m * (long long)k > n) {
            return -1; 
        }

        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
// test case
int main() {
    Solution solution;

    std::vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    int result = solution.minDays(bloomDay, m, k);

    std::cout << "Minimum number of days to make " << m << " bouquets: " << result << std::endl; 

    return 0;
}
