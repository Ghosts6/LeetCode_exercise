from collections import deque

class Solution:
    def orangesRotting(self, grid):
        if not grid or not grid[0]:
            return -1

        m, n = len(grid), len(grid[0])
        queue = deque()
        fresh_oranges = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh_oranges += 1

        if fresh_oranges == 0:
            return 0

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        minutes_elapsed = 0

        while queue:
            minutes_elapsed += 1
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                        grid[nx][ny] = 2
                        fresh_oranges -= 1
                        queue.append((nx, ny))

        return minutes_elapsed - 1 if fresh_oranges == 0 else -1

# test case
if __name__ == "__main__":
    solution = Solution()
    grid = [
        [2, 1, 1],
        [1, 1, 0],
        [0, 1, 1]
    ]
    result = solution.orangesRotting(grid)
    print(f"minimum number of minutes required: {result}")
