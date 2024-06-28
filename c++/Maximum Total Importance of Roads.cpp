#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        std::vector<int> cityConnections(n, 0);

        for (const auto& road : roads) {
            cityConnections[road[0]]++;
            cityConnections[road[1]]++;
        }

        std::vector<int> cityOrder(n);
        for (int i = 0; i < n; ++i) {
            cityOrder[i] = i;
        }
        
        std::sort(cityOrder.begin(), cityOrder.end(), [&cityConnections](int a, int b) {
            return cityConnections[a] > cityConnections[b];
        });

        std::vector<int> cityValues(n);
        for (int i = 0; i < n; ++i) {
            cityValues[cityOrder[i]] = n - i;
        }

        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += cityValues[road[0]] + cityValues[road[1]];
        }

        return totalImportance;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> roads = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    int n = 4;
    std::cout << "Maximum Importance: " << solution.maximumImportance(n, roads) << std::endl; 
    return 0;
}