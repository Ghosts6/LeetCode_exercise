# - Path with Maximum Gold


# 📜 Problem Description
In a gold mine grid of size m x n:
- Each cell represents the amount of gold (0 if empty).
- Conditions for collecting gold:
    - Collect all gold in the current cell.
    - Move one step left, right, up, or down.
    - Avoid revisiting cells or cells with 0 gold.
    - Start and stop gold collection from any position with gold.

Return the maximum gold you can collect.

# 💡Intuition
The problem involves finding the maximum amount of gold that can be collected from a grid. We start exploring from each cell with gold, performing backtracking to check all possible paths.

# 🛠️Approach
1.  Iterate through each cell of the grid.
2.  If the cell has gold, perform backtracking from that cell to explore all possible paths while collecting gold.
3.  During backtracking, try moving in all four directions (up, down, left, right) and calculate the maximum gold that can be collected.
4.  Keep track of the maximum gold collected overall.

# ⏰Complexity
- Time complexity:
    O(m * n * 4^k), where m and n are the dimensions of the grid and k is the average length of the paths from each cell containing gold.


- Space complexity:
    O(m * n) for the recursive call stack.

# 💻Code
### c++
```cpp
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
```
### python
```python
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
```
### java script
```javascript
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
```