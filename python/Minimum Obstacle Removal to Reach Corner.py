from heapq import heappush, heappop

class Solution:
    def minimumObstacles(self, grid):
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        pq = [(0, 0, 0)]
        visited = [[False] * n for _ in range(m)]
        
        while pq:
            obstacles_removed, x, y = heappop(pq)
            
            if (x, y) == (m - 1, n - 1):
                return obstacles_removed
            
            if visited[x][y]:
                continue
            visited[x][y] = True
            
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                    heappush(pq, (obstacles_removed + grid[nx][ny], nx, ny))
        
        return -1  

# Test cases
if __name__ == "__main__":
    sol = Solution()
    grid1 = [[0,1,1],[1,1,0],[1,1,0]]
    print("Output for grid1:", sol.minimumObstacles(grid1))  # Expected Output: 2
    
    grid2 = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
    print("Output for grid2:", sol.minimumObstacles(grid2))  # Expected Output: 0
