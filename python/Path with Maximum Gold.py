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