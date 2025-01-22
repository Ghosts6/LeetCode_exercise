#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        std::vector<std::vector<int>> heights(m, std::vector<int>(n, INT_MAX));
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

                    if (heights[nx][ny] > heights[x][y] + 1) {
                        heights[nx][ny] = heights[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return heights;
    }
};

// Test Case 
int main() {
    Solution Solution;

    // case 1:
    std::vector<std::vector<int>> isWater1 = {{0, 1}, {0, 0}};
    std::vector<std::vector<int>> result1 = Solution.highestPeak(isWater1);
    std::cout << "Test Case 1 Result:\n";
    for (const auto& row : result1) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    // case 2:
    std::vector<std::vector<int>> isWater2 = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    std::vector<std::vector<int>> result2 = Solution.highestPeak(isWater2);
    std::cout << "Test Case 2 Result:\n";
    for (const auto& row : result2) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
