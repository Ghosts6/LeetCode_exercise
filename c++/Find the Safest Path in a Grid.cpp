#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
        std::queue<std::pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        pq.push({dist[0][0], {0, 0}});
        std::vector<std::vector<int>> maxSafeness(n, std::vector<int>(n, -1));
        maxSafeness[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            if (r == n - 1 && c == n - 1) return d;

            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newSafe = std::min(d, dist[nr][nc]);
                    if (newSafe > maxSafeness[nr][nc]) {
                        maxSafeness[nr][nc] = newSafe;
                        pq.push({newSafe, {nr, nc}});
                    }
                }
            }
        }
        return -1;  
    }
};

// test cases
int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> grid2 = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    std::cout << "Output for grid1: " << solution.maximumSafenessFactor(grid1) << std::endl;
    std::cout << "Output for grid2: " << solution.maximumSafenessFactor(grid2) << std::endl;
    return 0;
}
