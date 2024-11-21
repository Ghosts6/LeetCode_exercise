from typing import List

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for _ in range(m)]

        for r, c in guards:
            grid[r][c] = 1
        for r, c in walls:
            grid[r][c] = 2

        for r in range(m):
            left_guard, right_guard = -1, -1
            for c in range(n):
                if grid[r][c] == 1:
                    left_guard = c
                elif grid[r][c] == 2:
                    left_guard = -1
                elif grid[r][c] == 0 and left_guard != -1:
                    grid[r][c] = 3

            for c in range(n - 1, -1, -1):
                if grid[r][c] == 1:
                    right_guard = c
                elif grid[r][c] == 2:
                    right_guard = -1
                elif grid[r][c] == 0 and right_guard != -1:
                    grid[r][c] = 3

        for c in range(n):
            top_guard, bottom_guard = -1, -1
            for r in range(m):
                if grid[r][c] == 1:
                    top_guard = r
                elif grid[r][c] == 2:
                    top_guard = -1
                elif grid[r][c] == 0 and top_guard != -1:
                    grid[r][c] = 3

            for r in range(m - 1, -1, -1):
                if grid[r][c] == 1:
                    bottom_guard = r
                elif grid[r][c] == 2:
                    bottom_guard = -1
                elif grid[r][c] == 0 and bottom_guard != -1:
                    grid[r][c] = 3

        unguarded_count = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 0:
                    unguarded_count += 1

        return unguarded_count
# test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    m = 4
    n = 6
    guards = [[0,0], [1,1], [2,3]]
    walls = [[0,1], [2,2], [1,4]]
    print(solution.countUnguarded(m, n, guards, walls))  # Expected output: 7

    # case 2
    m = 3
    n = 3
    guards = [[1,1]]
    walls = [[0,1], [1,0], [2,1], [1,2]]
    print(solution.countUnguarded(m, n, guards, walls))  # Expected output: 4
