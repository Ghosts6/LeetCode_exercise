class Solution:
    def numMagicSquaresInside(self, grid):
        def is_magic(r, c):
            nums = [grid[r+i][c+j] for i in range(3) for j in range(3)]
            if sorted(nums) != list(range(1, 10)):
                return False
  
            sum1 = grid[r][c] + grid[r][c+1] + grid[r][c+2]
            sum2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2]
            sum3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2]
            
            sum4 = grid[r][c] + grid[r+1][c] + grid[r+2][c]
            sum5 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1]
            sum6 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2]
            
            sum7 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]
            sum8 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]
            
            return (sum1 == sum2 == sum3 == sum4 == sum5 == sum6 == sum7 == sum8 == 15)
        
        count = 0
        rows = len(grid)
        cols = len(grid[0])
        
        for r in range(rows - 2):
            for c in range(cols - 2):
                if grid[r+1][c+1] == 5 and is_magic(r, c):
                    count += 1
                    
        return count

# Test case
grid = [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]

solution = Solution()
print(solution.numMagicSquaresInside(grid))  
