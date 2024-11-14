#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int left = 1, right = *std::max_element(quantities.begin(), quantities.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(n, quantities, mid)) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        
        return left;
    }

private:
    bool canDistribute(int n, std::vector<int>& quantities, int maxLoad) {
        int storesNeeded = 0;
        for (int quantity : quantities) {
            storesNeeded += (quantity + maxLoad - 1) / maxLoad;
            if (storesNeeded > n) {
                return false;
            }
        }
        return storesNeeded <= n;
    }
};

// Test cases 
int main() {
    Solution solution;

    // case 1
    int n1 = 6;
    std::vector<int> quantities1 = {11, 6};
    std::cout << "Output for test case 1: " << solution.minimizedMaximum(n1, quantities1) << std::endl; // Expected output: 3

    // case 2
    int n2 = 7;
    std::vector<int> quantities2 = {15, 10, 10};
    std::cout << "Output for test case 2: " << solution.minimizedMaximum(n2, quantities2) << std::endl; // Expected output: 5

    // case 3
    int n3 = 1;
    std::vector<int> quantities3 = {100000};
    std::cout << "Output for test case 3: " << solution.minimizedMaximum(n3, quantities3) << std::endl; // Expected output: 100000

    return 0;
}
