#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <iomanip>

class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            double gainA = ((double)a.first + 1) / (a.second + 1) - (double)a.first / a.second;
            double gainB = ((double)b.first + 1) / (b.second + 1) - (double)b.first / b.second;
            return gainA < gainB; 
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> maxHeap(compare);

        for (const auto& c : classes) {
            maxHeap.push({c[0], c[1]});
        }

        while (extraStudents-- > 0) {
            auto [pass, total] = maxHeap.top();
            maxHeap.pop();
            maxHeap.push({pass + 1, total + 1});
        }

        double totalAverage = 0.0;
        while (!maxHeap.empty()) {
            auto [pass, total] = maxHeap.top();
            maxHeap.pop();
            totalAverage += (double)pass / total;
        }

        return totalAverage / classes.size();
    }
};
// Test cases
int main() {
    Solution solution;
  
    // Test case 1
    std::vector<std::vector<int>> classes1 = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents1 = 2;
    double result1 = solution.maxAverageRatio(classes1, extraStudents1);
    std::cout << std::fixed << std::setprecision(5) << result1 << "\n"; // Expected output: 0.78333

    // Test case 2
    std::vector<std::vector<int>> classes2 = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    int extraStudents2 = 4;
    double result2 = solution.maxAverageRatio(classes2, extraStudents2);
    std::cout << std::fixed << std::setprecision(5) << result2 << "\n"; // Expected output: 0.53485

    return 0;
}
