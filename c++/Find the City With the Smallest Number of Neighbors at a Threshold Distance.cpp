#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minReachableCities = INT_MAX;
        int resultCity = -1;

        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            if (reachableCities < minReachableCities) {
                minReachableCities = reachableCities;
                resultCity = i;
            } else if (reachableCities == minReachableCities) {
                resultCity = std::max(resultCity, i);
            }
        }

        return resultCity;
    }
};
//  test case
void testSolution() {
    Solution solution;
    int n = 4;
    std::vector<std::vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {2, 3, 4}, {0, 3, 10}};
    int distanceThreshold = 4;
    int result = solution.findTheCity(n, edges, distanceThreshold);
    std::cout << "result (The city with the smallest number of reachable cities within distance threshold is): " << result << std::endl;
}

int main() {
    testSolution();
    return 0;
}
