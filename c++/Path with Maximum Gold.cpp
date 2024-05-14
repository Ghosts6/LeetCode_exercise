#include <iostream>
#include <vector>

class Solution {
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = std::max(maxGold, backtrack(grid, i, j));
                }
            }
        }
        return maxGold;
    }

    int backtrack(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        
        int gold = grid[i][j];
        grid[i][j] = 0;
        int maxGold = 0;
        maxGold = std::max(maxGold, gold + backtrack(grid, i - 1, j));
        maxGold = std::max(maxGold, gold + backtrack(grid, i + 1, j));
        maxGold = std::max(maxGold, gold + backtrack(grid, i, j - 1));
        maxGold = std::max(maxGold, gold + backtrack(grid, i, j + 1));
        grid[i][j] = gold;
        
        return maxGold;
    }
};
// test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    int result = solution.getMaximumGold(grid);
    std::cout << "maximum amount of gold collected: " << result << std::endl;
}


/* python
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        maxGold = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    maxGold = max(maxGold, self.backtrack(grid, i, j))
        return maxGold

    def backtrack(self, grid, i, j):
        m = len(grid)
        n = len(grid[0])

        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
            return 0

        gold = grid[i][j]
        grid[i][j] = 0
        maxGold = 0
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dx, dy in directions:
            maxGold = max(maxGold, gold + self.backtrack(grid, i + dx, j + dy))
        grid[i][j] = gold

        return maxGold
*/

/* java script
var getMaximumGold = function(grid) {
    const m = grid.length;
    const n = grid[0].length;

    function backtrack(i, j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] === 0) {
            return 0;
        }

        const gold = grid[i][j];
        grid[i][j] = 0;
        let maxGold = 0;
        const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
        for (const [dx, dy] of directions) {
            maxGold = Math.max(maxGold, gold + backtrack(i + dx, j + dy));
        }
        grid[i][j] = gold;

        return maxGold;
    }

    let maxGold = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] !== 0) {
                maxGold = Math.max(maxGold, backtrack(i, j));
            }
        }
    }
    return maxGold;
};
*/