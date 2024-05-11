#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <limits>

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        std::vector<std::pair<double, int>> ratioQuality;
        for (int i = 0; i < n; ++i) {
            ratioQuality.push_back({(double)wage[i] / quality[i], i});
        }
        std::sort(ratioQuality.begin(), ratioQuality.end());
        std::priority_queue<int> maxHeap;
        double minCost = std::numeric_limits<double>::max();
        double qualitySum = 0;
        for (auto [ratio, index] : ratioQuality) {
            qualitySum += quality[index];
            maxHeap.push(quality[index]);

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                minCost = std::min(minCost, ratio * qualitySum);
            }
        }
        return minCost;
    }
};
// test case
int main() {
    Solution solution;
    std::vector<int> quality1 = {10, 20, 5};
    std::vector<int> wage1 = {70, 50, 30};
    int k1 = 2;
    double result1 = solution.mincostToHireWorkers(quality1, wage1, k1);
    std::cout << "result pf test case: " << result1 << std::endl;
    return 0;
}
