# -Number of Islands

## 📜 Problem Description
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

# 💡Intuition
The problem involves counting the number of distinct islands in a grid. An island is a group of connected '1's (representing land) surrounded by '0's (representing water).

# 🛠️Approach
1. Iterate through each cell of the grid.
2. If the cell contains '1', increment the count of islands and perform Depth-First Search (DFS) to mark all connected land cells as visited ('0').
3. Repeat this process for all unvisited '1' cells in the grid.
4. The total count of islands represents the solution.

# ⏰Complexity
- Time complexity:
The time complexity of all the solutions is O(m * n), where m is the number of rows and n is the number of columns in the grid.

- Space complexity:
    In all the solutions, the space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This space is used for the call stack during DFS.

# 💻Code
### c++
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++numIslands;
                    dfs(grid, i, j);
                }
            }
        }

        return numIslands;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        dfs(grid, i + 1, j); 
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

```
### python
```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        numIslands = 0
        rows = len(grid)
        cols = len(grid[0])

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    numIslands += 1
                    self.dfs(grid, i, j)

        return numIslands

    def dfs(self, grid, i, j):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == '0':
            return

        grid[i][j] = '0'

        self.dfs(grid, i + 1, j)
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i, j + 1)
        self.dfs(grid, i, j - 1)
```
### java script
```javascript
var numIslands = function(grid) {
    if (grid.length === 0) return 0;

    let numIslands = 0;
    const rows = grid.length;
    const cols = grid[0].length;

    function dfs(i, j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] === '0')
            return;

        grid[i][j] = '0';

        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    for (let i = 0; i < rows; ++i) {
        for (let j = 0; j < cols; ++j) {
            if (grid[i][j] === '1') {
                ++numIslands;
                dfs(i, j);
            }
        }
    }

    return numIslands;
};
```