#include <iostream>
#include <vector>

class Solution {
public:
    bool dfs(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0) {
            return true;
        }

        if (grid1[i][j] == 0 && grid2[i][j] == 1) {
            return false;
        }

        grid2[i][j] = 0;

        bool isSubIsland = true;
        isSubIsland &= dfs(grid1, grid2, i + 1, j);
        isSubIsland &= dfs(grid1, grid2, i - 1, j);
        isSubIsland &= dfs(grid1, grid2, i, j + 1);
        isSubIsland &= dfs(grid1, grid2, i, j - 1);

        return isSubIsland;
    }

    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        int subIslandsCount = 0;

        for (int i = 0; i < grid2.size(); ++i) {
            for (int j = 0; j < grid2[0].size(); ++j) {
                if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j)) {
                    ++subIslandsCount;
                }
            }
        }

        return subIslandsCount;
    }
};

// Test cases
int main() {
    Solution solution;

    // case 1
    std::vector<std::vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    std::vector<std::vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    std::cout << "Number of sub-islands: " << solution.countSubIslands(grid1, grid2) << std::endl; // Output: 3

    // case 2
    grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
    std::cout << "Number of sub-islands: " << solution.countSubIslands(grid1, grid2) << std::endl; // Output: 2

    return 0;
}
