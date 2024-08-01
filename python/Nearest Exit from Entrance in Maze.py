from collections import deque

class Solution:
    def nearestExit(self, maze, entrance):
        rows, cols = len(maze), len(maze[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        queue = deque([(entrance[0], entrance[1], 0)])
        visited = set((entrance[0], entrance[1]))
        
        while queue:
            row, col, steps = queue.popleft()

            if (row != entrance[0] or col != entrance[1]) and (row == 0 or row == rows-1 or col == 0 or col == cols-1):
                return steps

            for dr, dc in directions:
                newRow, newCol = row + dr, col + dc

                if 0 <= newRow < rows and 0 <= newCol < cols and maze[newRow][newCol] == '.' and (newRow, newCol) not in visited:
                    visited.add((newRow, newCol))
                    queue.append((newRow, newCol, steps + 1))
        
        return -1

# test case
maze = [
    ['+','.','+','+','+','+'],
    ['+','.','+','.','.','+'],
    ['+','.','+','.','+','+'],
    ['+','.','.','.','+','+'],
    ['+','+','+','+','+','.']
]
entrance = [1, 1]

solution = Solution()
result = solution.nearestExit(maze, entrance)
print(f"number of steps to the nearest exit: {result}")
