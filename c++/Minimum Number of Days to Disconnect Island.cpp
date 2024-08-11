#include <vector>
#include <queue>
#include <iostream>

class Solution {
public:
    int minDays(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (countNumberOfIslands(grid) != 1) return 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; 
                    if (countNumberOfIslands(grid) != 1) {
                        return 1; 
                    }
                    grid[i][j] = 1; 
                }
            }
        }

        return 2; 
    }

private:
    int countNumberOfIslands(std::vector<std::vector<int>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ++islands;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return islands;
    }

    void bfs(int row, int col, std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        std::vector<int> dr = {-1, 1, 0, 0};
        std::vector<int> dc = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == 1 && !visited[newR][newC]) {
                    visited[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1}
    };
    
    int result = solution.minDays(grid);
    std::cout << "Minimum number of days to disconnect the grid: " << result << std::endl;

    return 0;
}

