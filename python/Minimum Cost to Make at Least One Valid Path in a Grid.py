from typing import List
from collections import deque

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)] 
        cost = [[float('inf')] * n for _ in range(m)]
        cost[0][0] = 0
        queue = deque([(0, 0)])

        while queue:
            x, y = queue.popleft()
            for i, (dx, dy) in enumerate(directions):
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    new_cost = cost[x][y] + (grid[x][y] != i + 1)
                    if new_cost < cost[nx][ny]:
                        cost[nx][ny] = new_cost
                        queue.append((nx, ny))

        return cost[m - 1][n - 1]
    
# Test case
if __name__ == "__main__":
    solution = Solution();
    # case 1
    grid1 = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
    print("Out put of Test case 1 is:", solution.minCost(grid1)) # Expected Output: 3
    # case 2
    grid2 = [[1,1,3],[3,2,2],[1,1,4]]
    print("Out put of Test case 2 is:", solution.minCost(grid2)) # Expected Output: 0
    # case 3
    grid3 = [[1,2],[4,3]]
    print("Out put of Test case 3 is:", solution.minCost(grid3)) # Expected Output: 1