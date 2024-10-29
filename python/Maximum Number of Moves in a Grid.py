from typing import List

class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        memo = {}

        def dfs(row: int, col: int) -> int:
            if (row, col) in memo:
                return memo[(row, col)]
            
            max_moves = 0
            for dr in [-1, 0, 1]:  
                new_row, new_col = row + dr, col + 1
                if 0 <= new_row < m and new_col < n and grid[new_row][new_col] > grid[row][col]:
                    max_moves = max(max_moves, 1 + dfs(new_row, new_col))
            
            memo[(row, col)] = max_moves
            return max_moves

        return max(dfs(row, 0) for row in range(m))

# Test cases
if __name__ == "__main__":
    # case 1
    grid1 = [[2, 4, 3, 5], [5, 4, 9, 3], [3, 4, 2, 11], [10, 9, 13, 15]]
    solution = Solution()
    print("Test case 1 output:", solution.maxMoves(grid1))  # Expected output: 3

    # case 2
    grid2 = [[3, 2, 4], [2, 1, 9], [1, 1, 7]]
    print("Test case 2 output:", solution.maxMoves(grid2))  # Expected output: 0
