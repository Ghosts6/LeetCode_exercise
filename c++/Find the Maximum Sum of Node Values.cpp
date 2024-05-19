#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        std::vector<std::vector<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        long long totalSum = 0;
        int positiveMin = INT_MAX;
        int negativeMax = INT_MIN;
        int count = 0;

        for (int nodeValue : nums) {
            int nodeValAfterOperation = nodeValue ^ k;
            totalSum += nodeValue;
            int netChange = nodeValAfterOperation - nodeValue;

            if (netChange > 0) {
                positiveMin = std::min(positiveMin, netChange);
                totalSum += netChange;
                count += 1;
            } else {
                negativeMax = std::max(negativeMax, netChange);
            }
        }
        if (count % 2 == 0) {
            return totalSum;
        }
        return std::max(totalSum - positiveMin, totalSum + negativeMax);
    }
};
// test case
int main() {
    Solution solution;
    
    std::vector<int> nums1 = {1, 2, 1};
    int k1 = 3;
    std::vector<std::vector<int>> edges1 = {{0, 1}, {0, 2}};
    std::cout << ".ax sum for test case 1: " << solution.maximumValueSum(nums1, k1, edges1) << std::endl;

    std::vector<int> nums2 = {2, 3, 4};
    int k2 = 2;
    std::vector<std::vector<int>> edges2 = {{0, 1}, {1, 2}};
    std::cout << "max sum for test case 2: " << solution.maximumValueSum(nums2, k2, edges2) << std::endl;

    return 0;
}

